/*
 * Copyright (C) 2011-2012 Daiki Ueno <ueno@unixuser.org>
 * Copyright (C) 2011-2012 Red Hat, Inc.
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
namespace Skk {
    // XXX: we use Vala string to represent byte array, assuming that
    // it does not contain null element
    class EncodingConverter : Object {
        static const int BUFSIZ = 4096;
        static const string INTERNAL_ENCODING = "UTF-8";

        internal string encoding { get; private set; }

        CharsetConverter encoder;
        CharsetConverter decoder;

        internal EncodingConverter (string encoding) throws GLib.Error {
            this.encoding = encoding;
            encoder = new CharsetConverter (encoding, INTERNAL_ENCODING);
            decoder = new CharsetConverter (INTERNAL_ENCODING, encoding);
        }

        string convert (CharsetConverter converter, string str) throws GLib.Error {
            uint8[] inbuf = str.data;
            uint8[] outbuf = new uint8[BUFSIZ];
            StringBuilder builder = new StringBuilder ();
            size_t total_bytes_read = 0;
            while (total_bytes_read < inbuf.length) {
                size_t bytes_read, bytes_written;
                // FIXME: we could split inbuf to small segments (<
                // BUFSIZ) here to reduce memory copy.  However it
                // requires proper error handling when the end of
                // segmented buffer lies across a UTF-8 character
                // boundary.
                converter.convert (inbuf[total_bytes_read : inbuf.length],
                                   outbuf,
                                   ConverterFlags.INPUT_AT_END,
                                   out bytes_read,
                                   out bytes_written);
                for (int i = 0; i < bytes_written; i++)
                    builder.append_c ((char)outbuf[i]);
                total_bytes_read += bytes_read;
            }
            return builder.str;
        }

        internal string encode (string internal_str) throws GLib.Error {
            return convert (encoder, internal_str);
        }

        internal string decode (string external_str) throws GLib.Error {
            return convert (decoder, external_str);
        }
    }
}
