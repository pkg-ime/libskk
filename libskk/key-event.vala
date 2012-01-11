/*
 * Copyright (C) 2011 Daiki Ueno <ueno@unixuser.org>
 * Copyright (C) 2011 Red Hat, Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
using Gee;

namespace Skk {
    /**
     * A set of bit-flags to indicate the state of modifier keys.
     */
    public enum ModifierType {
        NONE = 0,
        SHIFT_MASK = 1 << 0,
        LOCK_MASK = 1 << 1,
        CONTROL_MASK = 1 << 2,
        MOD1_MASK = 1 << 3,
        MOD2_MASK = 1 << 4,
        MOD3_MASK = 1 << 5,
        MOD4_MASK = 1 << 6,
        MOD5_MASK = 1 << 7,

        // dummy modifiers for NICOLA
        LSHIFT_MASK = 1 << 22,
        RSHIFT_MASK = 1 << 23,
        USLEEP_MASK = 1 << 24,

        SUPER_MASK = 1 << 26,
        HYPER_MASK = 1 << 27,
        META_MASK = 1 << 28,
        RELEASE_MASK = 1 << 30
    }

    /**
     * Object representing a key event.
     */
    public class KeyEvent {
        /**
         * The base name of the KeyEvent.
         *
         * This is exclusive to {@link code}.
         */
        public string? name { get; private set; }

        /**
         * The base code of the KeyEvent.
         *
         * This is exclusive to {@link name}.
         */
        public unichar code { get; private set; }

        /**
         * Modifier mask.
         */
        public ModifierType modifiers { get; set; }

        /**
         * Create a key event.
         *
         * @param name a key name
         * @param code a character code
         * @param modifiers state of modifier keys
         *
         * @return a new KeyEvent
         */
        public KeyEvent (string? name,
                         unichar code,
                         ModifierType modifiers) {
            this.name = name;
            this.code = code;
            this.modifiers = modifiers;
        }

        /**
         * Create a copy of the key event.
         *
         * @return a new KeyEvent
         */
        public KeyEvent copy () {
            return new KeyEvent (name, code, modifiers);
        }

        /**
         * Create a key event from string.
         *
         * @param key a string representation of a key event
         *
         * @return a new KeyEvent
         */
        public KeyEvent.from_string (string key) {
            if (key.has_prefix ("(") && key.has_suffix (")")) {
                var strv = key[1:-1].split (" ");
                int index = 0;
                for (; index < strv.length - 1; index++) {
                    if (strv[index] == "control") {
                        modifiers |= ModifierType.CONTROL_MASK;
                    } else if (strv[index] == "meta") {
                        modifiers |= ModifierType.META_MASK;
                    } else if (strv[index] == "hyper") {
                        modifiers |= ModifierType.HYPER_MASK;
                    } else if (strv[index] == "super") {
                        modifiers |= ModifierType.SUPER_MASK;
                    } else if (strv[index] == "alt") {
                        modifiers |= ModifierType.MOD1_MASK;
                    } else if (strv[index] == "lshift") {
                        modifiers |= ModifierType.LSHIFT_MASK;
                    } else if (strv[index] == "rshift") {
                        modifiers |= ModifierType.RSHIFT_MASK;
                    } else if (strv[index] == "usleep") {
                        modifiers |= ModifierType.USLEEP_MASK;
                    } else if (strv[index] == "release") {
                        modifiers |= ModifierType.RELEASE_MASK;
                    }
                }
                name = strv[index];
                code = name.char_count () == 1 ? name.get_char () : '\0';
            }
            else {
                int index = key.last_index_of ("-");
                if (index > 0) {
                    // support only limited modifiers in this form
                    string[] mods = key.substring (0, index).split ("-");
                    foreach (var mod in mods) {
                        if (mod == "C") {
                            modifiers |= ModifierType.CONTROL_MASK;
                        } else if (mod == "A") {
                            modifiers |= ModifierType.MOD1_MASK;
                        } else if (mod == "M") {
                            modifiers |= ModifierType.META_MASK;
                        } else if (mod == "G") {
                            modifiers |= ModifierType.MOD5_MASK;
                        }
                    }
                    name = key.substring (index + 1);
                    code = name.char_count () == 1 ? name.get_char () : '\0';
                } else {
                    modifiers = ModifierType.NONE;
                    name = key;
                    code = name.char_count () == 1 ? name.get_char () : '\0';
                }
            }
        }

        /**
         * Convert the KeyEvent to string.
         *
         * @return a string representing the KeyEvent
         */
        public string to_string () {
            string _base = name != null ? name : code.to_string ();
            if (modifiers != 0) {
                ArrayList<string?> elements = new ArrayList<string?> ();
                if ((modifiers & ModifierType.CONTROL_MASK) != 0) {
                    elements.add ("control");
                }
                if ((modifiers & ModifierType.META_MASK) != 0) {
                    elements.add ("meta");
                }
                if ((modifiers & ModifierType.HYPER_MASK) != 0) {
                    elements.add ("hyper");
                }
                if ((modifiers & ModifierType.SUPER_MASK) != 0) {
                    elements.add ("super");
                }
                if ((modifiers & ModifierType.MOD1_MASK) != 0) {
                    elements.add ("alt");
                }
                if ((modifiers & ModifierType.LSHIFT_MASK) != 0) {
                    elements.add ("lshift");
                }
                if ((modifiers & ModifierType.RSHIFT_MASK) != 0) {
                    elements.add ("rshift");
                }
                if ((modifiers & ModifierType.USLEEP_MASK) != 0) {
                    elements.add ("usleep");
                }
                if ((modifiers & ModifierType.RELEASE_MASK) != 0) {
                    elements.add ("release");
                }
                elements.add (_base);
                elements.add (null); // make sure that strv ends with null
                return "(" + string.joinv (" ", elements.to_array ()) + ")";
            } else {
                return _base;
            }
        }

        /**
         * Compare two key events ignoring modifiers.
         *
         * @param key a KeyEvent
         *
         * @return `true` if those base components are equal, `false` otherwise
         */
        public bool base_equal (KeyEvent key) {
            return code == key.code && name == key.name;
        }
    }

    /**
     * Base class of a key event filter.
     */
    public abstract class KeyEventFilter : Object {
        /**
         * Convert a key event to another.
         *
         * @param key a key event
         *
         * @return a KeyEvent or `null` if the result cannot be
         * fetched immediately
         */
        public abstract KeyEvent? filter_key_event (KeyEvent key);

        /**
         * Signal emitted when a new key event is generated in the filter.
         *
         * @param key a key event
         */
        public signal void forwarded (KeyEvent key);

        /**
         * Reset the filter.
         */
        public virtual void reset () {
        }
    }

    /**
     * Simple implementation of a key event filter.
     */
    public class SimpleKeyEventFilter : KeyEventFilter {
        /**
         * {@inheritDoc}
         */
        public override KeyEvent? filter_key_event (KeyEvent key) {
            // ignore key release event
            if ((key.modifiers & ModifierType.RELEASE_MASK) != 0)
                return null;
            // clear shift mask
            key.modifiers &= ~ModifierType.SHIFT_MASK;
            return key;
        }
    }
}
