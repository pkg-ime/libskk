/* skkserv.c generated by valac 0.14.0, the Vala compiler
 * generated from skkserv.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define SKK_TYPE_DICT (skk_dict_get_type ())
#define SKK_DICT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SKK_TYPE_DICT, SkkDict))
#define SKK_DICT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SKK_TYPE_DICT, SkkDictClass))
#define SKK_IS_DICT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SKK_TYPE_DICT))
#define SKK_IS_DICT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SKK_TYPE_DICT))
#define SKK_DICT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SKK_TYPE_DICT, SkkDictClass))

typedef struct _SkkDict SkkDict;
typedef struct _SkkDictClass SkkDictClass;
typedef struct _SkkDictPrivate SkkDictPrivate;

#define SKK_TYPE_CANDIDATE (skk_candidate_get_type ())
#define SKK_CANDIDATE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SKK_TYPE_CANDIDATE, SkkCandidate))
#define SKK_CANDIDATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SKK_TYPE_CANDIDATE, SkkCandidateClass))
#define SKK_IS_CANDIDATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SKK_TYPE_CANDIDATE))
#define SKK_IS_CANDIDATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SKK_TYPE_CANDIDATE))
#define SKK_CANDIDATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SKK_TYPE_CANDIDATE, SkkCandidateClass))

typedef struct _SkkCandidate SkkCandidate;
typedef struct _SkkCandidateClass SkkCandidateClass;

#define SKK_TYPE_SKK_SERV (skk_skk_serv_get_type ())
#define SKK_SKK_SERV(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SKK_TYPE_SKK_SERV, SkkSkkServ))
#define SKK_SKK_SERV_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SKK_TYPE_SKK_SERV, SkkSkkServClass))
#define SKK_IS_SKK_SERV(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SKK_TYPE_SKK_SERV))
#define SKK_IS_SKK_SERV_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SKK_TYPE_SKK_SERV))
#define SKK_SKK_SERV_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SKK_TYPE_SKK_SERV, SkkSkkServClass))

typedef struct _SkkSkkServ SkkSkkServ;
typedef struct _SkkSkkServClass SkkSkkServClass;
typedef struct _SkkSkkServPrivate SkkSkkServPrivate;

#define SKK_TYPE_ENCODING_CONVERTER (skk_encoding_converter_get_type ())
#define SKK_ENCODING_CONVERTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SKK_TYPE_ENCODING_CONVERTER, SkkEncodingConverter))
#define SKK_ENCODING_CONVERTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SKK_TYPE_ENCODING_CONVERTER, SkkEncodingConverterClass))
#define SKK_IS_ENCODING_CONVERTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SKK_TYPE_ENCODING_CONVERTER))
#define SKK_IS_ENCODING_CONVERTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SKK_TYPE_ENCODING_CONVERTER))
#define SKK_ENCODING_CONVERTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SKK_TYPE_ENCODING_CONVERTER, SkkEncodingConverterClass))

typedef struct _SkkEncodingConverter SkkEncodingConverter;
typedef struct _SkkEncodingConverterClass SkkEncodingConverterClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _skk_encoding_converter_unref0(var) ((var == NULL) ? NULL : (var = (skk_encoding_converter_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))

typedef enum  {
	SKK_SKK_SERV_ERROR_NOT_READABLE,
	SKK_SKK_SERV_ERROR_INVALID_RESPONSE
} SkkSkkServError;
#define SKK_SKK_SERV_ERROR skk_skk_serv_error_quark ()
struct _SkkDict {
	GObject parent_instance;
	SkkDictPrivate * priv;
};

struct _SkkDictClass {
	GObjectClass parent_class;
	void (*reload) (SkkDict* self, GError** error);
	SkkCandidate** (*lookup) (SkkDict* self, const gchar* midasi, gboolean okuri, int* result_length1);
	gchar** (*complete) (SkkDict* self, const gchar* midasi, int* result_length1);
	gboolean (*select_candidate) (SkkDict* self, SkkCandidate* candidate);
	gboolean (*purge_candidate) (SkkDict* self, SkkCandidate* candidate);
	void (*save) (SkkDict* self, GError** error);
	gboolean (*get_read_only) (SkkDict* self);
};

struct _SkkSkkServ {
	SkkDict parent_instance;
	SkkSkkServPrivate * priv;
};

struct _SkkSkkServClass {
	SkkDictClass parent_class;
};

struct _SkkSkkServPrivate {
	GSocketConnection* connection;
	guint8 buffer[4096];
	gchar* host;
	guint16 port;
	SkkEncodingConverter* converter;
};


static gpointer skk_skk_serv_parent_class = NULL;

GQuark skk_skk_serv_error_quark (void);
GType skk_dict_get_type (void) G_GNUC_CONST;
GType skk_candidate_get_type (void) G_GNUC_CONST;
GType skk_skk_serv_get_type (void) G_GNUC_CONST;
gpointer skk_encoding_converter_ref (gpointer instance);
void skk_encoding_converter_unref (gpointer instance);
GParamSpec* skk_param_spec_encoding_converter (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void skk_value_set_encoding_converter (GValue* value, gpointer v_object);
void skk_value_take_encoding_converter (GValue* value, gpointer v_object);
gpointer skk_value_get_encoding_converter (const GValue* value);
GType skk_encoding_converter_get_type (void) G_GNUC_CONST;
#define SKK_SKK_SERV_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SKK_TYPE_SKK_SERV, SkkSkkServPrivate))
enum  {
	SKK_SKK_SERV_DUMMY_PROPERTY,
	SKK_SKK_SERV_READ_ONLY
};
static void skk_skk_serv_real_reload (SkkDict* base, GError** error);
static gchar* skk_skk_serv_read_response (SkkSkkServ* self, GError** error);
static SkkCandidate** skk_skk_serv_real_lookup (SkkDict* base, const gchar* midasi, gboolean okuri, int* result_length1);
gchar* skk_encoding_converter_encode (SkkEncodingConverter* self, const gchar* internal_str, GError** error);
gchar* skk_encoding_converter_decode (SkkEncodingConverter* self, const gchar* external_str, GError** error);
SkkCandidate** skk_dict_split_candidates (SkkDict* self, const gchar* midasi, gboolean okuri, const gchar* line, int* result_length1);
static gchar** skk_skk_serv_real_complete (SkkDict* base, const gchar* midasi, int* result_length1);
SkkSkkServ* skk_skk_serv_new (const gchar* host, guint16 port, const gchar* encoding, GError** error);
SkkSkkServ* skk_skk_serv_construct (GType object_type, const gchar* host, guint16 port, const gchar* encoding, GError** error);
SkkDict* skk_dict_construct (GType object_type);
SkkEncodingConverter* skk_encoding_converter_new (const gchar* encoding, GError** error);
SkkEncodingConverter* skk_encoding_converter_construct (GType object_type, const gchar* encoding, GError** error);
void skk_dict_reload (SkkDict* self, GError** error);
static void skk_skk_serv_finalize (GObject* obj);
gboolean skk_dict_get_read_only (SkkDict* self);
static void _vala_skk_skk_serv_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static gint _vala_array_length (gpointer array);


GQuark skk_skk_serv_error_quark (void) {
	return g_quark_from_static_string ("skk_skk_serv_error-quark");
}


/**
         * {@inheritDoc}
         */
static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void skk_skk_serv_real_reload (SkkDict* base, GError** error) {
	SkkSkkServ * self;
	GSocketConnection* _tmp0_;
	GError * _inner_error_ = NULL;
	self = (SkkSkkServ*) base;
	_tmp0_ = self->priv->connection;
	if (_tmp0_ != NULL) {
		_g_object_unref0 (self->priv->connection);
		self->priv->connection = NULL;
	}
	{
		GSocketClient* _tmp1_;
		GSocketClient* client;
		GSocketClient* _tmp2_;
		const gchar* _tmp3_;
		guint16 _tmp4_;
		GSocketConnection* _tmp5_ = NULL;
		GSocketConnection* _tmp6_;
		GSocketConnection* _tmp7_;
		guint8 _tmp8_;
		gsize bytes_written = 0UL;
		GSocketConnection* _tmp9_;
		GOutputStream* _tmp10_;
		GOutputStream* _tmp11_;
		gsize _tmp12_ = 0UL;
		GSocketConnection* _tmp13_;
		GOutputStream* _tmp14_;
		GOutputStream* _tmp15_;
		GSocketConnection* _tmp16_;
		GInputStream* _tmp17_;
		GInputStream* _tmp18_;
		gssize _tmp19_ = 0L;
		gssize len;
		gssize _tmp20_;
		_tmp1_ = g_socket_client_new ();
		client = _tmp1_;
		_tmp2_ = client;
		_tmp3_ = self->priv->host;
		_tmp4_ = self->priv->port;
		_tmp5_ = g_socket_client_connect_to_host (_tmp2_, _tmp3_, _tmp4_, NULL, &_inner_error_);
		_tmp6_ = _tmp5_;
		if (_inner_error_ != NULL) {
			_g_object_unref0 (client);
			goto __catch15_g_error;
		}
		_tmp7_ = _g_object_ref0 (_tmp6_);
		_g_object_unref0 (self->priv->connection);
		self->priv->connection = _tmp7_;
		self->priv->buffer[0] = (guint8) '2';
		_tmp8_ = self->priv->buffer[0];
		_tmp9_ = self->priv->connection;
		_tmp10_ = g_io_stream_get_output_stream ((GIOStream*) _tmp9_);
		_tmp11_ = _tmp10_;
		g_output_stream_write_all (_tmp11_, self->priv->buffer + 0, (gsize) (1 - 0), &_tmp12_, NULL, &_inner_error_);
		bytes_written = _tmp12_;
		if (_inner_error_ != NULL) {
			_g_object_unref0 (client);
			goto __catch15_g_error;
		}
		_tmp13_ = self->priv->connection;
		_tmp14_ = g_io_stream_get_output_stream ((GIOStream*) _tmp13_);
		_tmp15_ = _tmp14_;
		g_output_stream_flush (_tmp15_, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_object_unref0 (client);
			goto __catch15_g_error;
		}
		_tmp16_ = self->priv->connection;
		_tmp17_ = g_io_stream_get_input_stream ((GIOStream*) _tmp16_);
		_tmp18_ = _tmp17_;
		_tmp19_ = g_input_stream_read (_tmp18_, self->priv->buffer, (gsize) 4096, NULL, &_inner_error_);
		len = _tmp19_;
		if (_inner_error_ != NULL) {
			_g_object_unref0 (client);
			goto __catch15_g_error;
		}
		_tmp20_ = len;
		if (_tmp20_ <= ((gssize) 0)) {
			_g_object_unref0 (self->priv->connection);
			self->priv->connection = NULL;
		}
		_g_object_unref0 (client);
	}
	goto __finally15;
	__catch15_g_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_g_object_unref0 (self->priv->connection);
		self->priv->connection = NULL;
		_g_error_free0 (e);
	}
	__finally15:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static gint string_index_of_char (const gchar* self, gunichar c, gint start_index) {
	gint result = 0;
	gint _tmp0_;
	gunichar _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* _result_;
	gchar* _tmp3_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = start_index;
	_tmp1_ = c;
	_tmp2_ = g_utf8_strchr (((gchar*) self) + _tmp0_, (gssize) (-1), _tmp1_);
	_result_ = _tmp2_;
	_tmp3_ = _result_;
	if (_tmp3_ != NULL) {
		gchar* _tmp4_;
		_tmp4_ = _result_;
		result = (gint) (_tmp4_ - ((gchar*) self));
		return result;
	} else {
		result = -1;
		return result;
	}
}


static gchar* string_slice (const gchar* self, glong start, glong end) {
	gchar* result = NULL;
	gint _tmp0_;
	gint _tmp1_;
	glong string_length;
	glong _tmp2_;
	glong _tmp5_;
	gboolean _tmp8_ = FALSE;
	glong _tmp9_;
	gboolean _tmp12_;
	gboolean _tmp13_ = FALSE;
	glong _tmp14_;
	gboolean _tmp17_;
	glong _tmp18_;
	glong _tmp19_;
	glong _tmp20_;
	glong _tmp21_;
	glong _tmp22_;
	gchar* _tmp23_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = strlen (self);
	_tmp1_ = _tmp0_;
	string_length = (glong) _tmp1_;
	_tmp2_ = start;
	if (_tmp2_ < ((glong) 0)) {
		glong _tmp3_;
		glong _tmp4_;
		_tmp3_ = string_length;
		_tmp4_ = start;
		start = _tmp3_ + _tmp4_;
	}
	_tmp5_ = end;
	if (_tmp5_ < ((glong) 0)) {
		glong _tmp6_;
		glong _tmp7_;
		_tmp6_ = string_length;
		_tmp7_ = end;
		end = _tmp6_ + _tmp7_;
	}
	_tmp9_ = start;
	if (_tmp9_ >= ((glong) 0)) {
		glong _tmp10_;
		glong _tmp11_;
		_tmp10_ = start;
		_tmp11_ = string_length;
		_tmp8_ = _tmp10_ <= _tmp11_;
	} else {
		_tmp8_ = FALSE;
	}
	_tmp12_ = _tmp8_;
	g_return_val_if_fail (_tmp12_, NULL);
	_tmp14_ = end;
	if (_tmp14_ >= ((glong) 0)) {
		glong _tmp15_;
		glong _tmp16_;
		_tmp15_ = end;
		_tmp16_ = string_length;
		_tmp13_ = _tmp15_ <= _tmp16_;
	} else {
		_tmp13_ = FALSE;
	}
	_tmp17_ = _tmp13_;
	g_return_val_if_fail (_tmp17_, NULL);
	_tmp18_ = start;
	_tmp19_ = end;
	g_return_val_if_fail (_tmp18_ <= _tmp19_, NULL);
	_tmp20_ = start;
	_tmp21_ = end;
	_tmp22_ = start;
	_tmp23_ = g_strndup (((gchar*) self) + _tmp20_, (gsize) (_tmp21_ - _tmp22_));
	result = _tmp23_;
	return result;
}


static gchar* skk_skk_serv_read_response (SkkSkkServ* self, GError** error) {
	gchar* result = NULL;
	GString* _tmp0_;
	GString* builder;
	GString* _tmp21_;
	const gchar* _tmp22_;
	gint _tmp23_ = 0;
	gint index;
	gint _tmp24_;
	GString* _tmp26_;
	const gchar* _tmp27_;
	gint _tmp28_;
	gchar* _tmp29_ = NULL;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_string_new ("");
	builder = _tmp0_;
	while (TRUE) {
		GString* _tmp1_;
		const gchar* _tmp2_;
		gint _tmp3_ = 0;
		GSocketConnection* _tmp4_;
		GInputStream* _tmp5_;
		GInputStream* _tmp6_;
		gssize _tmp7_ = 0L;
		gssize len;
		gssize _tmp8_;
		_tmp1_ = builder;
		_tmp2_ = _tmp1_->str;
		_tmp3_ = string_index_of_char (_tmp2_, (gunichar) '\n', 0);
		if (!(_tmp3_ < 0)) {
			break;
		}
		_tmp4_ = self->priv->connection;
		_tmp5_ = g_io_stream_get_input_stream ((GIOStream*) _tmp4_);
		_tmp6_ = _tmp5_;
		_tmp7_ = g_input_stream_read (_tmp6_, self->priv->buffer, (gsize) 4096, NULL, &_inner_error_);
		len = _tmp7_;
		if (_inner_error_ != NULL) {
			if ((_inner_error_->domain == SKK_SKK_SERV_ERROR) || (_inner_error_->domain == G_IO_ERROR)) {
				g_propagate_error (error, _inner_error_);
				_g_string_free0 (builder);
				return NULL;
			} else {
				_g_string_free0 (builder);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
		_tmp8_ = len;
		if (_tmp8_ < ((gssize) 0)) {
			GError* _tmp9_;
			_tmp9_ = g_error_new_literal (SKK_SKK_SERV_ERROR, SKK_SKK_SERV_ERROR_NOT_READABLE, "read error");
			_inner_error_ = _tmp9_;
			if ((_inner_error_->domain == SKK_SKK_SERV_ERROR) || (_inner_error_->domain == G_IO_ERROR)) {
				g_propagate_error (error, _inner_error_);
				_g_string_free0 (builder);
				return NULL;
			} else {
				_g_string_free0 (builder);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		} else {
			gssize _tmp10_;
			_tmp10_ = len;
			if (_tmp10_ == ((gssize) 0)) {
				break;
			} else {
				gssize _tmp11_;
				_tmp11_ = len;
				if (_tmp11_ > ((gssize) 0)) {
					guint8 _tmp12_;
					gssize _tmp14_;
					gchar* _tmp15_ = NULL;
					gchar* data;
					gint data_length1;
					gint _data_size_;
					gchar* _tmp16_;
					gint _tmp16__length1;
					gssize _tmp17_;
					gint _tmp18_;
					GString* _tmp19_;
					gchar* _tmp20_;
					gint _tmp20__length1;
					_tmp12_ = self->priv->buffer[0];
					if (_tmp12_ != ((guint8) '1')) {
						GError* _tmp13_;
						_tmp13_ = g_error_new_literal (SKK_SKK_SERV_ERROR, SKK_SKK_SERV_ERROR_INVALID_RESPONSE, "invalid response code");
						_inner_error_ = _tmp13_;
						if ((_inner_error_->domain == SKK_SKK_SERV_ERROR) || (_inner_error_->domain == G_IO_ERROR)) {
							g_propagate_error (error, _inner_error_);
							_g_string_free0 (builder);
							return NULL;
						} else {
							_g_string_free0 (builder);
							g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
							g_clear_error (&_inner_error_);
							return NULL;
						}
					}
					_tmp14_ = len;
					_tmp15_ = g_new0 (gchar, _tmp14_ + 1);
					data = _tmp15_;
					data_length1 = _tmp14_ + 1;
					_data_size_ = data_length1;
					_tmp16_ = data;
					_tmp16__length1 = data_length1;
					_tmp17_ = len;
					memcpy (_tmp16_, self->priv->buffer, (gsize) _tmp17_);
					_tmp18_ = data_length1;
					data_length1 = _tmp18_ - 1;
					_tmp19_ = builder;
					_tmp20_ = data;
					_tmp20__length1 = data_length1;
					g_string_append (_tmp19_, (const gchar*) _tmp20_);
					data = (g_free (data), NULL);
				}
			}
		}
	}
	_tmp21_ = builder;
	_tmp22_ = _tmp21_->str;
	_tmp23_ = string_index_of_char (_tmp22_, (gunichar) '\n', 0);
	index = _tmp23_;
	_tmp24_ = index;
	if (_tmp24_ < 0) {
		GError* _tmp25_;
		_tmp25_ = g_error_new_literal (SKK_SKK_SERV_ERROR, SKK_SKK_SERV_ERROR_INVALID_RESPONSE, "missing newline");
		_inner_error_ = _tmp25_;
		if ((_inner_error_->domain == SKK_SKK_SERV_ERROR) || (_inner_error_->domain == G_IO_ERROR)) {
			g_propagate_error (error, _inner_error_);
			_g_string_free0 (builder);
			return NULL;
		} else {
			_g_string_free0 (builder);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_tmp26_ = builder;
	_tmp27_ = _tmp26_->str;
	_tmp28_ = index;
	_tmp29_ = string_slice (_tmp27_, (glong) 0, (glong) _tmp28_);
	result = _tmp29_;
	_g_string_free0 (builder);
	return result;
}


/**
         * {@inheritDoc}
         */
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


static SkkCandidate** skk_skk_serv_real_lookup (SkkDict* base, const gchar* midasi, gboolean okuri, int* result_length1) {
	SkkSkkServ * self;
	SkkCandidate** result = NULL;
	GSocketConnection* _tmp0_;
	gchar* _midasi = NULL;
	GError * _inner_error_ = NULL;
	self = (SkkSkkServ*) base;
	g_return_val_if_fail (midasi != NULL, NULL);
	_tmp0_ = self->priv->connection;
	if (_tmp0_ == NULL) {
		SkkCandidate** _tmp1_ = NULL;
		SkkCandidate** _tmp2_;
		gint _tmp2__length1;
		_tmp1_ = g_new0 (SkkCandidate*, 0 + 1);
		_tmp2_ = _tmp1_;
		_tmp2__length1 = 0;
		if (result_length1) {
			*result_length1 = _tmp2__length1;
		}
		result = _tmp2_;
		return result;
	}
	{
		SkkEncodingConverter* _tmp3_;
		const gchar* _tmp4_;
		gchar* _tmp5_ = NULL;
		gchar* _tmp6_;
		_tmp3_ = self->priv->converter;
		_tmp4_ = midasi;
		_tmp5_ = skk_encoding_converter_encode (_tmp3_, _tmp4_, &_inner_error_);
		_tmp6_ = _tmp5_;
		if (_inner_error_ != NULL) {
			goto __catch16_g_error;
		}
		_g_free0 (_midasi);
		_midasi = _tmp6_;
	}
	goto __finally16;
	__catch16_g_error:
	{
		GError* e = NULL;
		SkkCandidate** _tmp7_ = NULL;
		SkkCandidate** _tmp8_;
		gint _tmp8__length1;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp7_ = g_new0 (SkkCandidate*, 0 + 1);
		_tmp8_ = _tmp7_;
		_tmp8__length1 = 0;
		if (result_length1) {
			*result_length1 = _tmp8__length1;
		}
		result = _tmp8_;
		_g_error_free0 (e);
		_g_free0 (_midasi);
		return result;
	}
	__finally16:
	if (_inner_error_ != NULL) {
		_g_free0 (_midasi);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	{
		gsize bytes_written = 0UL;
		GSocketConnection* _tmp9_;
		GOutputStream* _tmp10_;
		GOutputStream* _tmp11_;
		const gchar* _tmp12_;
		gchar* _tmp13_ = NULL;
		gchar* _tmp14_;
		guint8* _tmp15_;
		gint _tmp15__length1;
		guint8* _tmp16_;
		gint _tmp16__length1;
		gsize _tmp17_ = 0UL;
		GSocketConnection* _tmp18_;
		GOutputStream* _tmp19_;
		GOutputStream* _tmp20_;
		gchar* _tmp21_ = NULL;
		gchar* response;
		const gchar* _tmp22_;
		gint _tmp23_;
		gint _tmp24_;
		SkkEncodingConverter* _tmp27_;
		const gchar* _tmp28_;
		const gchar* _tmp29_;
		gint _tmp30_;
		gint _tmp31_;
		gchar* _tmp32_ = NULL;
		gchar* _tmp33_;
		gchar* _tmp34_ = NULL;
		gchar* _tmp35_;
		gchar* _tmp36_;
		const gchar* _tmp37_;
		gboolean _tmp38_;
		gchar* _tmp39_;
		gint _tmp40_ = 0;
		SkkCandidate** _tmp41_ = NULL;
		SkkCandidate** _tmp42_;
		gint _tmp42__length1;
		SkkCandidate** _tmp43_;
		gint _tmp43__length1;
		_tmp9_ = self->priv->connection;
		_tmp10_ = g_io_stream_get_output_stream ((GIOStream*) _tmp9_);
		_tmp11_ = _tmp10_;
		_tmp12_ = _midasi;
		_tmp13_ = g_strdup_printf ("1%s ", _tmp12_);
		_tmp14_ = _tmp13_;
		_tmp15_ = string_get_data (_tmp14_, &_tmp15__length1);
		_tmp16_ = _tmp15_;
		_tmp16__length1 = _tmp15__length1;
		g_output_stream_write_all (_tmp11_, _tmp16_, (gsize) _tmp16__length1, &_tmp17_, NULL, &_inner_error_);
		bytes_written = _tmp17_;
		_g_free0 (_tmp14_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == SKK_SKK_SERV_ERROR) {
				goto __catch17_skk_skk_serv_error;
			}
			goto __catch17_g_error;
		}
		_tmp18_ = self->priv->connection;
		_tmp19_ = g_io_stream_get_output_stream ((GIOStream*) _tmp18_);
		_tmp20_ = _tmp19_;
		g_output_stream_flush (_tmp20_, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == SKK_SKK_SERV_ERROR) {
				goto __catch17_skk_skk_serv_error;
			}
			goto __catch17_g_error;
		}
		_tmp21_ = skk_skk_serv_read_response (self, &_inner_error_);
		response = _tmp21_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == SKK_SKK_SERV_ERROR) {
				goto __catch17_skk_skk_serv_error;
			}
			goto __catch17_g_error;
		}
		_tmp22_ = response;
		_tmp23_ = strlen (_tmp22_);
		_tmp24_ = _tmp23_;
		if (_tmp24_ == 0) {
			SkkCandidate** _tmp25_ = NULL;
			SkkCandidate** _tmp26_;
			gint _tmp26__length1;
			_tmp25_ = g_new0 (SkkCandidate*, 0 + 1);
			_tmp26_ = _tmp25_;
			_tmp26__length1 = 0;
			if (result_length1) {
				*result_length1 = _tmp26__length1;
			}
			result = _tmp26_;
			_g_free0 (response);
			_g_free0 (_midasi);
			return result;
		}
		_tmp27_ = self->priv->converter;
		_tmp28_ = response;
		_tmp29_ = response;
		_tmp30_ = strlen (_tmp29_);
		_tmp31_ = _tmp30_;
		_tmp32_ = string_slice (_tmp28_, (glong) 1, (glong) _tmp31_);
		_tmp33_ = _tmp32_;
		_tmp34_ = skk_encoding_converter_decode (_tmp27_, _tmp33_, &_inner_error_);
		_tmp35_ = _tmp34_;
		_g_free0 (_tmp33_);
		_tmp36_ = _tmp35_;
		if (_inner_error_ != NULL) {
			_g_free0 (response);
			if (_inner_error_->domain == SKK_SKK_SERV_ERROR) {
				goto __catch17_skk_skk_serv_error;
			}
			goto __catch17_g_error;
		}
		_tmp37_ = midasi;
		_tmp38_ = okuri;
		_tmp39_ = _tmp36_;
		_tmp41_ = skk_dict_split_candidates ((SkkDict*) self, _tmp37_, _tmp38_, _tmp39_, &_tmp40_);
		_tmp42_ = _tmp41_;
		_tmp42__length1 = _tmp40_;
		_g_free0 (_tmp39_);
		_tmp43_ = _tmp42_;
		_tmp43__length1 = _tmp42__length1;
		if (result_length1) {
			*result_length1 = _tmp43__length1;
		}
		result = _tmp43_;
		_g_free0 (response);
		_g_free0 (_midasi);
		return result;
	}
	goto __finally17;
	__catch17_skk_skk_serv_error:
	{
		GError* e = NULL;
		SkkCandidate** _tmp44_ = NULL;
		SkkCandidate** _tmp45_;
		gint _tmp45__length1;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp44_ = g_new0 (SkkCandidate*, 0 + 1);
		_tmp45_ = _tmp44_;
		_tmp45__length1 = 0;
		if (result_length1) {
			*result_length1 = _tmp45__length1;
		}
		result = _tmp45_;
		_g_error_free0 (e);
		_g_free0 (_midasi);
		return result;
	}
	goto __finally17;
	__catch17_g_error:
	{
		GError* e = NULL;
		SkkCandidate** _tmp46_ = NULL;
		SkkCandidate** _tmp47_;
		gint _tmp47__length1;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp46_ = g_new0 (SkkCandidate*, 0 + 1);
		_tmp47_ = _tmp46_;
		_tmp47__length1 = 0;
		if (result_length1) {
			*result_length1 = _tmp47__length1;
		}
		result = _tmp47_;
		_g_error_free0 (e);
		_g_free0 (_midasi);
		return result;
	}
	__finally17:
	_g_free0 (_midasi);
	g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
	g_clear_error (&_inner_error_);
	return NULL;
}


/**
         * {@inheritDoc}
         */
static gchar** skk_skk_serv_real_complete (SkkDict* base, const gchar* midasi, int* result_length1) {
	SkkSkkServ * self;
	gchar** result = NULL;
	GSocketConnection* _tmp0_;
	gchar* _midasi = NULL;
	GError * _inner_error_ = NULL;
	self = (SkkSkkServ*) base;
	g_return_val_if_fail (midasi != NULL, NULL);
	_tmp0_ = self->priv->connection;
	if (_tmp0_ == NULL) {
		gchar** _tmp1_ = NULL;
		gchar** _tmp2_;
		gint _tmp2__length1;
		_tmp1_ = g_new0 (gchar*, 0 + 1);
		_tmp2_ = _tmp1_;
		_tmp2__length1 = 0;
		if (result_length1) {
			*result_length1 = _tmp2__length1;
		}
		result = _tmp2_;
		return result;
	}
	{
		SkkEncodingConverter* _tmp3_;
		const gchar* _tmp4_;
		gchar* _tmp5_ = NULL;
		gchar* _tmp6_;
		_tmp3_ = self->priv->converter;
		_tmp4_ = midasi;
		_tmp5_ = skk_encoding_converter_encode (_tmp3_, _tmp4_, &_inner_error_);
		_tmp6_ = _tmp5_;
		if (_inner_error_ != NULL) {
			goto __catch18_g_error;
		}
		_g_free0 (_midasi);
		_midasi = _tmp6_;
	}
	goto __finally18;
	__catch18_g_error:
	{
		GError* e = NULL;
		gchar** _tmp7_ = NULL;
		gchar** _tmp8_;
		gint _tmp8__length1;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp7_ = g_new0 (gchar*, 0 + 1);
		_tmp8_ = _tmp7_;
		_tmp8__length1 = 0;
		if (result_length1) {
			*result_length1 = _tmp8__length1;
		}
		result = _tmp8_;
		_g_error_free0 (e);
		_g_free0 (_midasi);
		return result;
	}
	__finally18:
	if (_inner_error_ != NULL) {
		_g_free0 (_midasi);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	{
		gsize bytes_written = 0UL;
		GSocketConnection* _tmp9_;
		GOutputStream* _tmp10_;
		GOutputStream* _tmp11_;
		const gchar* _tmp12_;
		gchar* _tmp13_ = NULL;
		gchar* _tmp14_;
		guint8* _tmp15_;
		gint _tmp15__length1;
		guint8* _tmp16_;
		gint _tmp16__length1;
		gsize _tmp17_ = 0UL;
		GSocketConnection* _tmp18_;
		GOutputStream* _tmp19_;
		GOutputStream* _tmp20_;
		gchar* _tmp21_ = NULL;
		gchar* response;
		const gchar* _tmp22_;
		gint _tmp23_;
		gint _tmp24_;
		SkkEncodingConverter* _tmp27_;
		const gchar* _tmp28_;
		const gchar* _tmp29_;
		gint _tmp30_;
		gint _tmp31_;
		gchar* _tmp32_ = NULL;
		gchar* _tmp33_;
		gchar* _tmp34_ = NULL;
		gchar* _tmp35_;
		gchar* _tmp36_;
		gchar* _tmp37_;
		gchar** _tmp38_;
		gchar** _tmp39_ = NULL;
		gchar** _tmp40_;
		gint _tmp40__length1;
		gchar** _tmp41_;
		gint _tmp41__length1;
		_tmp9_ = self->priv->connection;
		_tmp10_ = g_io_stream_get_output_stream ((GIOStream*) _tmp9_);
		_tmp11_ = _tmp10_;
		_tmp12_ = _midasi;
		_tmp13_ = g_strdup_printf ("4%s ", _tmp12_);
		_tmp14_ = _tmp13_;
		_tmp15_ = string_get_data (_tmp14_, &_tmp15__length1);
		_tmp16_ = _tmp15_;
		_tmp16__length1 = _tmp15__length1;
		g_output_stream_write_all (_tmp11_, _tmp16_, (gsize) _tmp16__length1, &_tmp17_, NULL, &_inner_error_);
		bytes_written = _tmp17_;
		_g_free0 (_tmp14_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == SKK_SKK_SERV_ERROR) {
				goto __catch19_skk_skk_serv_error;
			}
			goto __catch19_g_error;
		}
		_tmp18_ = self->priv->connection;
		_tmp19_ = g_io_stream_get_output_stream ((GIOStream*) _tmp18_);
		_tmp20_ = _tmp19_;
		g_output_stream_flush (_tmp20_, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == SKK_SKK_SERV_ERROR) {
				goto __catch19_skk_skk_serv_error;
			}
			goto __catch19_g_error;
		}
		_tmp21_ = skk_skk_serv_read_response (self, &_inner_error_);
		response = _tmp21_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == SKK_SKK_SERV_ERROR) {
				goto __catch19_skk_skk_serv_error;
			}
			goto __catch19_g_error;
		}
		_tmp22_ = response;
		_tmp23_ = strlen (_tmp22_);
		_tmp24_ = _tmp23_;
		if (_tmp24_ < 2) {
			gchar** _tmp25_ = NULL;
			gchar** _tmp26_;
			gint _tmp26__length1;
			_tmp25_ = g_new0 (gchar*, 0 + 1);
			_tmp26_ = _tmp25_;
			_tmp26__length1 = 0;
			if (result_length1) {
				*result_length1 = _tmp26__length1;
			}
			result = _tmp26_;
			_g_free0 (response);
			_g_free0 (_midasi);
			return result;
		}
		_tmp27_ = self->priv->converter;
		_tmp28_ = response;
		_tmp29_ = response;
		_tmp30_ = strlen (_tmp29_);
		_tmp31_ = _tmp30_;
		_tmp32_ = string_slice (_tmp28_, (glong) 2, (glong) _tmp31_);
		_tmp33_ = _tmp32_;
		_tmp34_ = skk_encoding_converter_decode (_tmp27_, _tmp33_, &_inner_error_);
		_tmp35_ = _tmp34_;
		_g_free0 (_tmp33_);
		_tmp36_ = _tmp35_;
		if (_inner_error_ != NULL) {
			_g_free0 (response);
			if (_inner_error_->domain == SKK_SKK_SERV_ERROR) {
				goto __catch19_skk_skk_serv_error;
			}
			goto __catch19_g_error;
		}
		_tmp37_ = _tmp36_;
		_tmp39_ = _tmp38_ = g_strsplit (_tmp37_, "/", 0);
		_tmp40_ = _tmp39_;
		_tmp40__length1 = _vala_array_length (_tmp38_);
		_g_free0 (_tmp37_);
		_tmp41_ = _tmp40_;
		_tmp41__length1 = _tmp40__length1;
		if (result_length1) {
			*result_length1 = _tmp41__length1;
		}
		result = _tmp41_;
		_g_free0 (response);
		_g_free0 (_midasi);
		return result;
	}
	goto __finally19;
	__catch19_skk_skk_serv_error:
	{
		GError* e = NULL;
		GError* _tmp42_;
		const gchar* _tmp43_;
		gchar** _tmp44_ = NULL;
		gchar** _tmp45_;
		gint _tmp45__length1;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp42_ = e;
		_tmp43_ = _tmp42_->message;
		g_warning ("skkserv.vala:142: server completion failed %s", _tmp43_);
		_tmp44_ = g_new0 (gchar*, 0 + 1);
		_tmp45_ = _tmp44_;
		_tmp45__length1 = 0;
		if (result_length1) {
			*result_length1 = _tmp45__length1;
		}
		result = _tmp45_;
		_g_error_free0 (e);
		_g_free0 (_midasi);
		return result;
	}
	goto __finally19;
	__catch19_g_error:
	{
		GError* e = NULL;
		GError* _tmp46_;
		const gchar* _tmp47_;
		gchar** _tmp48_ = NULL;
		gchar** _tmp49_;
		gint _tmp49__length1;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp46_ = e;
		_tmp47_ = _tmp46_->message;
		g_warning ("skkserv.vala:145: server completion failed %s", _tmp47_);
		_tmp48_ = g_new0 (gchar*, 0 + 1);
		_tmp49_ = _tmp48_;
		_tmp49__length1 = 0;
		if (result_length1) {
			*result_length1 = _tmp49__length1;
		}
		result = _tmp49_;
		_g_error_free0 (e);
		_g_free0 (_midasi);
		return result;
	}
	__finally19:
	_g_free0 (_midasi);
	g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
	g_clear_error (&_inner_error_);
	return NULL;
}


/**
         * Create a new SkkServ.
         *
         * @param host host to connect
         * @param port port at the host
         * @param encoding encoding to convert text over network traffic
         *
         * @return a new SkkServ.
         * @throws GLib.Error if opening a connection is failed
         */
SkkSkkServ* skk_skk_serv_construct (GType object_type, const gchar* host, guint16 port, const gchar* encoding, GError** error) {
	SkkSkkServ * self = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	guint16 _tmp2_;
	const gchar* _tmp3_;
	SkkEncodingConverter* _tmp4_;
	SkkEncodingConverter* _tmp5_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (host != NULL, NULL);
	g_return_val_if_fail (encoding != NULL, NULL);
	self = (SkkSkkServ*) skk_dict_construct (object_type);
	_tmp0_ = host;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->host);
	self->priv->host = _tmp1_;
	_tmp2_ = port;
	self->priv->port = _tmp2_;
	_tmp3_ = encoding;
	_tmp4_ = skk_encoding_converter_new (_tmp3_, &_inner_error_);
	_tmp5_ = _tmp4_;
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (self);
		return NULL;
	}
	_skk_encoding_converter_unref0 (self->priv->converter);
	self->priv->converter = _tmp5_;
	skk_dict_reload ((SkkDict*) self, &_inner_error_);
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (self);
		return NULL;
	}
	return self;
}


SkkSkkServ* skk_skk_serv_new (const gchar* host, guint16 port, const gchar* encoding, GError** error) {
	return skk_skk_serv_construct (SKK_TYPE_SKK_SERV, host, port, encoding, error);
}


static gboolean skk_skk_serv_real_get_read_only (SkkDict* base) {
	gboolean result;
	SkkSkkServ* self;
	self = (SkkSkkServ*) base;
	result = TRUE;
	return result;
}


static void skk_skk_serv_class_init (SkkSkkServClass * klass) {
	skk_skk_serv_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (SkkSkkServPrivate));
	SKK_DICT_CLASS (klass)->reload = skk_skk_serv_real_reload;
	SKK_DICT_CLASS (klass)->lookup = skk_skk_serv_real_lookup;
	SKK_DICT_CLASS (klass)->complete = skk_skk_serv_real_complete;
	SKK_DICT_CLASS (klass)->get_read_only = skk_skk_serv_real_get_read_only;
	G_OBJECT_CLASS (klass)->get_property = _vala_skk_skk_serv_get_property;
	G_OBJECT_CLASS (klass)->finalize = skk_skk_serv_finalize;
	/**
	         * {@inheritDoc}
	         */
	g_object_class_override_property (G_OBJECT_CLASS (klass), SKK_SKK_SERV_READ_ONLY, "read-only");
}


static void skk_skk_serv_instance_init (SkkSkkServ * self) {
	self->priv = SKK_SKK_SERV_GET_PRIVATE (self);
}


static void skk_skk_serv_finalize (GObject* obj) {
	SkkSkkServ * self;
	self = SKK_SKK_SERV (obj);
	_g_object_unref0 (self->priv->connection);
	_g_free0 (self->priv->host);
	_skk_encoding_converter_unref0 (self->priv->converter);
	G_OBJECT_CLASS (skk_skk_serv_parent_class)->finalize (obj);
}


/**
     * An implementation of Dict which talks the skkserv protocol.
     */
GType skk_skk_serv_get_type (void) {
	static volatile gsize skk_skk_serv_type_id__volatile = 0;
	if (g_once_init_enter (&skk_skk_serv_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SkkSkkServClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) skk_skk_serv_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SkkSkkServ), 0, (GInstanceInitFunc) skk_skk_serv_instance_init, NULL };
		GType skk_skk_serv_type_id;
		skk_skk_serv_type_id = g_type_register_static (SKK_TYPE_DICT, "SkkSkkServ", &g_define_type_info, 0);
		g_once_init_leave (&skk_skk_serv_type_id__volatile, skk_skk_serv_type_id);
	}
	return skk_skk_serv_type_id__volatile;
}


static void _vala_skk_skk_serv_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	SkkSkkServ * self;
	self = SKK_SKK_SERV (object);
	switch (property_id) {
		case SKK_SKK_SERV_READ_ONLY:
		g_value_set_boolean (value, skk_dict_get_read_only ((SkkDict*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}


