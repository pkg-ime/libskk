/* encoding.c generated by valac 0.14.0, the Vala compiler
 * generated from encoding.vala, do not modify */

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

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define SKK_TYPE_ENCODING_CONVERTER (skk_encoding_converter_get_type ())
#define SKK_ENCODING_CONVERTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SKK_TYPE_ENCODING_CONVERTER, SkkEncodingConverter))
#define SKK_ENCODING_CONVERTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SKK_TYPE_ENCODING_CONVERTER, SkkEncodingConverterClass))
#define SKK_IS_ENCODING_CONVERTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SKK_TYPE_ENCODING_CONVERTER))
#define SKK_IS_ENCODING_CONVERTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SKK_TYPE_ENCODING_CONVERTER))
#define SKK_ENCODING_CONVERTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SKK_TYPE_ENCODING_CONVERTER, SkkEncodingConverterClass))

typedef struct _SkkEncodingConverter SkkEncodingConverter;
typedef struct _SkkEncodingConverterClass SkkEncodingConverterClass;
typedef struct _SkkEncodingConverterPrivate SkkEncodingConverterPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))

struct _SkkEncodingConverter {
	GObject parent_instance;
	SkkEncodingConverterPrivate * priv;
};

struct _SkkEncodingConverterClass {
	GObjectClass parent_class;
};

struct _SkkEncodingConverterPrivate {
	gchar* _encoding;
	GCharsetConverter* encoder;
	GCharsetConverter* decoder;
};


static gpointer skk_encoding_converter_parent_class = NULL;

GType skk_encoding_converter_get_type (void) G_GNUC_CONST;
#define SKK_ENCODING_CONVERTER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SKK_TYPE_ENCODING_CONVERTER, SkkEncodingConverterPrivate))
enum  {
	SKK_ENCODING_CONVERTER_DUMMY_PROPERTY,
	SKK_ENCODING_CONVERTER_ENCODING
};
#define SKK_ENCODING_CONVERTER_BUFSIZ 4096
#define SKK_ENCODING_CONVERTER_INTERNAL_ENCODING "UTF-8"
SkkEncodingConverter* skk_encoding_converter_new (const gchar* encoding, GError** error);
SkkEncodingConverter* skk_encoding_converter_construct (GType object_type, const gchar* encoding, GError** error);
static void skk_encoding_converter_set_encoding (SkkEncodingConverter* self, const gchar* value);
static gchar* skk_encoding_converter_convert (SkkEncodingConverter* self, GCharsetConverter* converter, const gchar* str, GError** error);
static guint8* _vala_array_dup1 (guint8* self, int length);
gchar* skk_encoding_converter_encode (SkkEncodingConverter* self, const gchar* internal_str, GError** error);
gchar* skk_encoding_converter_decode (SkkEncodingConverter* self, const gchar* external_str, GError** error);
const gchar* skk_encoding_converter_get_encoding (SkkEncodingConverter* self);
static void skk_encoding_converter_finalize (GObject* obj);
static void _vala_skk_encoding_converter_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_skk_encoding_converter_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


SkkEncodingConverter* skk_encoding_converter_construct (GType object_type, const gchar* encoding, GError** error) {
	SkkEncodingConverter * self = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	GCharsetConverter* _tmp2_;
	GCharsetConverter* _tmp3_;
	const gchar* _tmp4_;
	GCharsetConverter* _tmp5_;
	GCharsetConverter* _tmp6_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (encoding != NULL, NULL);
	self = (SkkEncodingConverter*) g_object_new (object_type, NULL);
	_tmp0_ = encoding;
	skk_encoding_converter_set_encoding (self, _tmp0_);
	_tmp1_ = encoding;
	_tmp2_ = g_charset_converter_new (_tmp1_, SKK_ENCODING_CONVERTER_INTERNAL_ENCODING, &_inner_error_);
	_tmp3_ = _tmp2_;
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (self);
		return NULL;
	}
	_g_object_unref0 (self->priv->encoder);
	self->priv->encoder = _tmp3_;
	_tmp4_ = encoding;
	_tmp5_ = g_charset_converter_new (SKK_ENCODING_CONVERTER_INTERNAL_ENCODING, _tmp4_, &_inner_error_);
	_tmp6_ = _tmp5_;
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (self);
		return NULL;
	}
	_g_object_unref0 (self->priv->decoder);
	self->priv->decoder = _tmp6_;
	return self;
}


SkkEncodingConverter* skk_encoding_converter_new (const gchar* encoding, GError** error) {
	return skk_encoding_converter_construct (SKK_TYPE_ENCODING_CONVERTER, encoding, error);
}


static guint8* string_get_data (const gchar* self, int* result_length1) {
	guint8* result;
	guint8* res;
	gint res_length1;
	gint _res_size_;
	gint _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	guint8* _tmp3_;
	gint _tmp3__length1;
	guint8* _tmp4_;
	gint _tmp4__length1;
	g_return_val_if_fail (self != NULL, NULL);
	res = (guint8*) self;
	res_length1 = -1;
	_res_size_ = res_length1;
	_tmp0_ = strlen (self);
	_tmp1_ = _tmp0_;
	res_length1 = (gint) _tmp1_;
	_tmp2_ = res_length1;
	_tmp3_ = res;
	_tmp3__length1 = res_length1;
	_tmp4_ = _tmp3_;
	_tmp4__length1 = _tmp3__length1;
	if (result_length1) {
		*result_length1 = _tmp4__length1;
	}
	result = _tmp4_;
	return result;
}


static guint8* _vala_array_dup1 (guint8* self, int length) {
	return g_memdup (self, length * sizeof (guint8));
}


static gchar* skk_encoding_converter_convert (SkkEncodingConverter* self, GCharsetConverter* converter, const gchar* str, GError** error) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	guint8* _tmp1_;
	gint _tmp1__length1;
	guint8* _tmp2_;
	gint _tmp2__length1;
	guint8* _tmp3_;
	gint _tmp3__length1;
	guint8* inbuf;
	gint inbuf_length1;
	gint _inbuf_size_;
	guint8* _tmp4_ = NULL;
	guint8* outbuf;
	gint outbuf_length1;
	gint _outbuf_size_;
	GString* _tmp5_;
	GString* builder;
	gsize total_bytes_read;
	GString* _tmp26_;
	const gchar* _tmp27_;
	gchar* _tmp28_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (converter != NULL, NULL);
	g_return_val_if_fail (str != NULL, NULL);
	_tmp0_ = str;
	_tmp1_ = string_get_data (_tmp0_, &_tmp1__length1);
	_tmp2_ = _tmp1_;
	_tmp2__length1 = _tmp1__length1;
	_tmp3_ = (_tmp2_ != NULL) ? _vala_array_dup1 (_tmp2_, _tmp2__length1) : ((gpointer) _tmp2_);
	_tmp3__length1 = _tmp2__length1;
	inbuf = _tmp3_;
	inbuf_length1 = _tmp3__length1;
	_inbuf_size_ = inbuf_length1;
	_tmp4_ = g_new0 (guint8, SKK_ENCODING_CONVERTER_BUFSIZ);
	outbuf = _tmp4_;
	outbuf_length1 = SKK_ENCODING_CONVERTER_BUFSIZ;
	_outbuf_size_ = outbuf_length1;
	_tmp5_ = g_string_new ("");
	builder = _tmp5_;
	total_bytes_read = (gsize) 0;
	while (TRUE) {
		gsize _tmp6_;
		guint8* _tmp7_;
		gint _tmp7__length1;
		gsize bytes_read = 0UL;
		gsize bytes_written = 0UL;
		GCharsetConverter* _tmp8_;
		guint8* _tmp9_;
		gint _tmp9__length1;
		gsize _tmp10_;
		guint8* _tmp11_;
		gint _tmp11__length1;
		guint8* _tmp12_;
		gint _tmp12__length1;
		gsize _tmp13_ = 0UL;
		gsize _tmp14_ = 0UL;
		gsize _tmp24_;
		gsize _tmp25_;
		_tmp6_ = total_bytes_read;
		_tmp7_ = inbuf;
		_tmp7__length1 = inbuf_length1;
		if (!(_tmp6_ < ((gsize) _tmp7__length1))) {
			break;
		}
		_tmp8_ = converter;
		_tmp9_ = inbuf;
		_tmp9__length1 = inbuf_length1;
		_tmp10_ = total_bytes_read;
		_tmp11_ = inbuf;
		_tmp11__length1 = inbuf_length1;
		_tmp12_ = outbuf;
		_tmp12__length1 = outbuf_length1;
		g_converter_convert ((GConverter*) _tmp8_, _tmp9_ + _tmp10_, (gsize) (_tmp11__length1 - _tmp10_), _tmp12_, (gsize) _tmp12__length1, G_CONVERTER_INPUT_AT_END, &_tmp13_, &_tmp14_, &_inner_error_);
		bytes_read = _tmp13_;
		bytes_written = _tmp14_;
		if (_inner_error_ != NULL) {
			g_propagate_error (error, _inner_error_);
			_g_string_free0 (builder);
			outbuf = (g_free (outbuf), NULL);
			inbuf = (g_free (inbuf), NULL);
			return NULL;
		}
		{
			gint i;
			i = 0;
			{
				gboolean _tmp15_;
				_tmp15_ = TRUE;
				while (TRUE) {
					gboolean _tmp16_;
					gint _tmp18_;
					gsize _tmp19_;
					GString* _tmp20_;
					guint8* _tmp21_;
					gint _tmp21__length1;
					gint _tmp22_;
					guint8 _tmp23_;
					_tmp16_ = _tmp15_;
					if (!_tmp16_) {
						gint _tmp17_;
						_tmp17_ = i;
						i = _tmp17_ + 1;
					}
					_tmp15_ = FALSE;
					_tmp18_ = i;
					_tmp19_ = bytes_written;
					if (!(((gsize) _tmp18_) < _tmp19_)) {
						break;
					}
					_tmp20_ = builder;
					_tmp21_ = outbuf;
					_tmp21__length1 = outbuf_length1;
					_tmp22_ = i;
					_tmp23_ = _tmp21_[_tmp22_];
					g_string_append_c (_tmp20_, (gchar) _tmp23_);
				}
			}
		}
		_tmp24_ = total_bytes_read;
		_tmp25_ = bytes_read;
		total_bytes_read = _tmp24_ + _tmp25_;
	}
	_tmp26_ = builder;
	_tmp27_ = _tmp26_->str;
	_tmp28_ = g_strdup (_tmp27_);
	result = _tmp28_;
	_g_string_free0 (builder);
	outbuf = (g_free (outbuf), NULL);
	inbuf = (g_free (inbuf), NULL);
	return result;
}


gchar* skk_encoding_converter_encode (SkkEncodingConverter* self, const gchar* internal_str, GError** error) {
	gchar* result = NULL;
	GCharsetConverter* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (internal_str != NULL, NULL);
	_tmp0_ = self->priv->encoder;
	_tmp1_ = internal_str;
	_tmp2_ = skk_encoding_converter_convert (self, _tmp0_, _tmp1_, &_inner_error_);
	_tmp3_ = _tmp2_;
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	result = _tmp3_;
	return result;
}


gchar* skk_encoding_converter_decode (SkkEncodingConverter* self, const gchar* external_str, GError** error) {
	gchar* result = NULL;
	GCharsetConverter* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (external_str != NULL, NULL);
	_tmp0_ = self->priv->decoder;
	_tmp1_ = external_str;
	_tmp2_ = skk_encoding_converter_convert (self, _tmp0_, _tmp1_, &_inner_error_);
	_tmp3_ = _tmp2_;
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		return NULL;
	}
	result = _tmp3_;
	return result;
}


const gchar* skk_encoding_converter_get_encoding (SkkEncodingConverter* self) {
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_encoding;
	result = _tmp0_;
	return result;
}


static void skk_encoding_converter_set_encoding (SkkEncodingConverter* self, const gchar* value) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_encoding);
	self->priv->_encoding = _tmp1_;
	g_object_notify ((GObject *) self, "encoding");
}


static void skk_encoding_converter_class_init (SkkEncodingConverterClass * klass) {
	skk_encoding_converter_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (SkkEncodingConverterPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_skk_encoding_converter_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_skk_encoding_converter_set_property;
	G_OBJECT_CLASS (klass)->finalize = skk_encoding_converter_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SKK_ENCODING_CONVERTER_ENCODING, g_param_spec_string ("encoding", "encoding", "encoding", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void skk_encoding_converter_instance_init (SkkEncodingConverter * self) {
	self->priv = SKK_ENCODING_CONVERTER_GET_PRIVATE (self);
}


static void skk_encoding_converter_finalize (GObject* obj) {
	SkkEncodingConverter * self;
	self = SKK_ENCODING_CONVERTER (obj);
	_g_free0 (self->priv->_encoding);
	_g_object_unref0 (self->priv->encoder);
	_g_object_unref0 (self->priv->decoder);
	G_OBJECT_CLASS (skk_encoding_converter_parent_class)->finalize (obj);
}


GType skk_encoding_converter_get_type (void) {
	static volatile gsize skk_encoding_converter_type_id__volatile = 0;
	if (g_once_init_enter (&skk_encoding_converter_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SkkEncodingConverterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) skk_encoding_converter_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SkkEncodingConverter), 0, (GInstanceInitFunc) skk_encoding_converter_instance_init, NULL };
		GType skk_encoding_converter_type_id;
		skk_encoding_converter_type_id = g_type_register_static (G_TYPE_OBJECT, "SkkEncodingConverter", &g_define_type_info, 0);
		g_once_init_leave (&skk_encoding_converter_type_id__volatile, skk_encoding_converter_type_id);
	}
	return skk_encoding_converter_type_id__volatile;
}


static void _vala_skk_encoding_converter_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	SkkEncodingConverter * self;
	self = SKK_ENCODING_CONVERTER (object);
	switch (property_id) {
		case SKK_ENCODING_CONVERTER_ENCODING:
		g_value_set_string (value, skk_encoding_converter_get_encoding (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_skk_encoding_converter_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	SkkEncodingConverter * self;
	self = SKK_ENCODING_CONVERTER (object);
	switch (property_id) {
		case SKK_ENCODING_CONVERTER_ENCODING:
		skk_encoding_converter_set_encoding (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



