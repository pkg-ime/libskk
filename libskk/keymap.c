/* keymap.c generated by valac 0.14.0, the Vala compiler
 * generated from keymap.vala, do not modify */

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

#include <glib.h>
#include <glib-object.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>


#define SKK_TYPE_KEYMAP (skk_keymap_get_type ())
#define SKK_KEYMAP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SKK_TYPE_KEYMAP, SkkKeymap))
#define SKK_KEYMAP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SKK_TYPE_KEYMAP, SkkKeymapClass))
#define SKK_IS_KEYMAP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SKK_TYPE_KEYMAP))
#define SKK_IS_KEYMAP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SKK_TYPE_KEYMAP))
#define SKK_KEYMAP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SKK_TYPE_KEYMAP, SkkKeymapClass))

typedef struct _SkkKeymap SkkKeymap;
typedef struct _SkkKeymapClass SkkKeymapClass;
typedef struct _SkkKeymapPrivate SkkKeymapPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define SKK_TYPE_KEY_EVENT (skk_key_event_get_type ())
#define SKK_KEY_EVENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SKK_TYPE_KEY_EVENT, SkkKeyEvent))
#define SKK_KEY_EVENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SKK_TYPE_KEY_EVENT, SkkKeyEventClass))
#define SKK_IS_KEY_EVENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SKK_TYPE_KEY_EVENT))
#define SKK_IS_KEY_EVENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SKK_TYPE_KEY_EVENT))
#define SKK_KEY_EVENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SKK_TYPE_KEY_EVENT, SkkKeyEventClass))

typedef struct _SkkKeyEvent SkkKeyEvent;
typedef struct _SkkKeyEventClass SkkKeyEventClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _skk_key_event_unref0(var) ((var == NULL) ? NULL : (var = (skk_key_event_unref (var), NULL)))

struct _SkkKeymap {
	GObject parent_instance;
	SkkKeymapPrivate * priv;
};

struct _SkkKeymapClass {
	GObjectClass parent_class;
};

struct _SkkKeymapPrivate {
	GeeMap* entries;
};


static gpointer skk_keymap_parent_class = NULL;

GType skk_keymap_get_type (void) G_GNUC_CONST;
#define SKK_KEYMAP_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SKK_TYPE_KEYMAP, SkkKeymapPrivate))
enum  {
	SKK_KEYMAP_DUMMY_PROPERTY
};
void skk_keymap_set (SkkKeymap* self, const gchar* key, const gchar* command);
SkkKeyEvent* skk_key_event_new_from_string (const gchar* key);
SkkKeyEvent* skk_key_event_construct_from_string (GType object_type, const gchar* key);
gpointer skk_key_event_ref (gpointer instance);
void skk_key_event_unref (gpointer instance);
GParamSpec* skk_param_spec_key_event (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void skk_value_set_key_event (GValue* value, gpointer v_object);
void skk_value_take_key_event (GValue* value, gpointer v_object);
gpointer skk_value_get_key_event (const GValue* value);
GType skk_key_event_get_type (void) G_GNUC_CONST;
gchar* skk_key_event_to_string (SkkKeyEvent* self);
gchar* skk_keymap_lookup_key (SkkKeymap* self, SkkKeyEvent* key);
SkkKeyEvent* skk_keymap_where_is (SkkKeymap* self, const gchar* command);
SkkKeymap* skk_keymap_new (void);
SkkKeymap* skk_keymap_construct (GType object_type);
static void skk_keymap_finalize (GObject* obj);


void skk_keymap_set (SkkKeymap* self, const gchar* key, const gchar* command) {
	GeeMap* _tmp0_;
	const gchar* _tmp1_;
	SkkKeyEvent* _tmp2_;
	SkkKeyEvent* _tmp3_;
	gchar* _tmp4_ = NULL;
	gchar* _tmp5_;
	const gchar* _tmp6_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (key != NULL);
	g_return_if_fail (command != NULL);
	_tmp0_ = self->priv->entries;
	_tmp1_ = key;
	_tmp2_ = skk_key_event_new_from_string (_tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = skk_key_event_to_string (_tmp3_);
	_tmp5_ = _tmp4_;
	_tmp6_ = command;
	gee_map_set (_tmp0_, _tmp5_, _tmp6_);
	_g_free0 (_tmp5_);
	_skk_key_event_unref0 (_tmp3_);
}


gchar* skk_keymap_lookup_key (SkkKeymap* self, SkkKeyEvent* key) {
	gchar* result = NULL;
	GeeMap* _tmp0_;
	SkkKeyEvent* _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_;
	gpointer _tmp4_ = NULL;
	gchar* _tmp5_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	_tmp0_ = self->priv->entries;
	_tmp1_ = key;
	_tmp2_ = skk_key_event_to_string (_tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = gee_map_get (_tmp0_, _tmp3_);
	_tmp5_ = (gchar*) _tmp4_;
	_g_free0 (_tmp3_);
	result = _tmp5_;
	return result;
}


SkkKeyEvent* skk_keymap_where_is (SkkKeymap* self, const gchar* command) {
	SkkKeyEvent* result = NULL;
	GeeMap* _tmp0_;
	GeeMapIterator* _tmp1_ = NULL;
	GeeMapIterator* iter;
	GeeMapIterator* _tmp2_;
	gboolean _tmp3_ = FALSE;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (command != NULL, NULL);
	_tmp0_ = self->priv->entries;
	_tmp1_ = gee_map_map_iterator (_tmp0_);
	iter = _tmp1_;
	_tmp2_ = iter;
	_tmp3_ = gee_map_iterator_first (_tmp2_);
	if (_tmp3_) {
		{
			gboolean _tmp4_;
			_tmp4_ = TRUE;
			while (TRUE) {
				gboolean _tmp5_;
				GeeMapIterator* _tmp8_;
				gpointer _tmp9_ = NULL;
				gchar* _tmp10_;
				const gchar* _tmp11_;
				gboolean _tmp12_;
				_tmp5_ = _tmp4_;
				if (!_tmp5_) {
					GeeMapIterator* _tmp6_;
					gboolean _tmp7_ = FALSE;
					_tmp6_ = iter;
					_tmp7_ = gee_map_iterator_next (_tmp6_);
					if (!_tmp7_) {
						break;
					}
				}
				_tmp4_ = FALSE;
				_tmp8_ = iter;
				_tmp9_ = gee_map_iterator_get_value (_tmp8_);
				_tmp10_ = (gchar*) _tmp9_;
				_tmp11_ = command;
				_tmp12_ = g_strcmp0 (_tmp10_, _tmp11_) == 0;
				_g_free0 (_tmp10_);
				if (_tmp12_) {
					GeeMapIterator* _tmp13_;
					gpointer _tmp14_ = NULL;
					gchar* _tmp15_;
					SkkKeyEvent* _tmp16_;
					SkkKeyEvent* _tmp17_;
					_tmp13_ = iter;
					_tmp14_ = gee_map_iterator_get_key (_tmp13_);
					_tmp15_ = (gchar*) _tmp14_;
					_tmp16_ = skk_key_event_new_from_string (_tmp15_);
					_tmp17_ = _tmp16_;
					_g_free0 (_tmp15_);
					result = _tmp17_;
					_g_object_unref0 (iter);
					return result;
				}
			}
		}
	}
	result = NULL;
	_g_object_unref0 (iter);
	return result;
}


SkkKeymap* skk_keymap_construct (GType object_type) {
	SkkKeymap * self = NULL;
	self = (SkkKeymap*) g_object_new (object_type, NULL);
	return self;
}


SkkKeymap* skk_keymap_new (void) {
	return skk_keymap_construct (SKK_TYPE_KEYMAP);
}


static void skk_keymap_class_init (SkkKeymapClass * klass) {
	skk_keymap_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (SkkKeymapPrivate));
	G_OBJECT_CLASS (klass)->finalize = skk_keymap_finalize;
}


static void skk_keymap_instance_init (SkkKeymap * self) {
	GeeHashMap* _tmp0_;
	self->priv = SKK_KEYMAP_GET_PRIVATE (self);
	_tmp0_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL, NULL, NULL);
	self->priv->entries = (GeeMap*) _tmp0_;
}


static void skk_keymap_finalize (GObject* obj) {
	SkkKeymap * self;
	self = SKK_KEYMAP (obj);
	_g_object_unref0 (self->priv->entries);
	G_OBJECT_CLASS (skk_keymap_parent_class)->finalize (obj);
}


GType skk_keymap_get_type (void) {
	static volatile gsize skk_keymap_type_id__volatile = 0;
	if (g_once_init_enter (&skk_keymap_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SkkKeymapClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) skk_keymap_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SkkKeymap), 0, (GInstanceInitFunc) skk_keymap_instance_init, NULL };
		GType skk_keymap_type_id;
		skk_keymap_type_id = g_type_register_static (G_TYPE_OBJECT, "SkkKeymap", &g_define_type_info, 0);
		g_once_init_leave (&skk_keymap_type_id__volatile, skk_keymap_type_id);
	}
	return skk_keymap_type_id__volatile;
}



