/* candidate.c generated by valac 0.14.0, the Vala compiler
 * generated from candidate.vala, do not modify */

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


#define SKK_TYPE_CANDIDATE (skk_candidate_get_type ())
#define SKK_CANDIDATE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SKK_TYPE_CANDIDATE, SkkCandidate))
#define SKK_CANDIDATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SKK_TYPE_CANDIDATE, SkkCandidateClass))
#define SKK_IS_CANDIDATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SKK_TYPE_CANDIDATE))
#define SKK_IS_CANDIDATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SKK_TYPE_CANDIDATE))
#define SKK_CANDIDATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SKK_TYPE_CANDIDATE, SkkCandidateClass))

typedef struct _SkkCandidate SkkCandidate;
typedef struct _SkkCandidateClass SkkCandidateClass;
typedef struct _SkkCandidatePrivate SkkCandidatePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _SkkCandidate {
	GObject parent_instance;
	SkkCandidatePrivate * priv;
};

struct _SkkCandidateClass {
	GObjectClass parent_class;
};

struct _SkkCandidatePrivate {
	gchar* _midasi;
	gboolean _okuri;
	gchar* _text;
	gchar* _annotation;
	gchar* _output;
};


static gpointer skk_candidate_parent_class = NULL;

GType skk_candidate_get_type (void) G_GNUC_CONST;
#define SKK_CANDIDATE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SKK_TYPE_CANDIDATE, SkkCandidatePrivate))
enum  {
	SKK_CANDIDATE_DUMMY_PROPERTY,
	SKK_CANDIDATE_MIDASI,
	SKK_CANDIDATE_OKURI,
	SKK_CANDIDATE_TEXT,
	SKK_CANDIDATE_ANNOTATION,
	SKK_CANDIDATE_OUTPUT
};
gchar* skk_candidate_to_string (SkkCandidate* self);
const gchar* skk_candidate_get_annotation (SkkCandidate* self);
const gchar* skk_candidate_get_text (SkkCandidate* self);
SkkCandidate* skk_candidate_new (const gchar* midasi, gboolean okuri, const gchar* text, const gchar* annotation, const gchar* output);
SkkCandidate* skk_candidate_construct (GType object_type, const gchar* midasi, gboolean okuri, const gchar* text, const gchar* annotation, const gchar* output);
static void skk_candidate_set_midasi (SkkCandidate* self, const gchar* value);
static void skk_candidate_set_okuri (SkkCandidate* self, gboolean value);
void skk_candidate_set_text (SkkCandidate* self, const gchar* value);
void skk_candidate_set_annotation (SkkCandidate* self, const gchar* value);
void skk_candidate_set_output (SkkCandidate* self, const gchar* value);
const gchar* skk_candidate_get_midasi (SkkCandidate* self);
gboolean skk_candidate_get_okuri (SkkCandidate* self);
const gchar* skk_candidate_get_output (SkkCandidate* self);
static void skk_candidate_finalize (GObject* obj);
static void _vala_skk_candidate_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_skk_candidate_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


/**
         * Convert the candidate to string.
         * @return a string representing the candidate
         */
gchar* skk_candidate_to_string (SkkCandidate* self) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_annotation;
	if (_tmp0_ != NULL) {
		const gchar* _tmp1_;
		gchar* _tmp2_;
		gchar* _tmp3_;
		const gchar* _tmp4_;
		gchar* _tmp5_;
		gchar* _tmp6_;
		_tmp1_ = self->priv->_text;
		_tmp2_ = g_strconcat (_tmp1_, ";", NULL);
		_tmp3_ = _tmp2_;
		_tmp4_ = self->priv->_annotation;
		_tmp5_ = g_strconcat (_tmp3_, _tmp4_, NULL);
		_tmp6_ = _tmp5_;
		_g_free0 (_tmp3_);
		result = _tmp6_;
		return result;
	} else {
		const gchar* _tmp7_;
		gchar* _tmp8_;
		_tmp7_ = self->priv->_text;
		_tmp8_ = g_strdup (_tmp7_);
		result = _tmp8_;
		return result;
	}
}


/**
         * Create a new Candidate.
         *
         * @param midasi midasi (index) word which generate the candidate
         * @param okuri whether the candidate is a result of okuri-ari conversion
         * @param text base string value of the candidate
         * @param annotation optional annotation text to the candidate
         * @param output optional output text used instead of text
         *
         * @return a new SkkCandidate
         */
SkkCandidate* skk_candidate_construct (GType object_type, const gchar* midasi, gboolean okuri, const gchar* text, const gchar* annotation, const gchar* output) {
	SkkCandidate * self = NULL;
	const gchar* _tmp0_;
	gboolean _tmp1_;
	const gchar* _tmp2_;
	const gchar* _tmp3_;
	const gchar* _tmp4_ = NULL;
	const gchar* _tmp5_;
	const gchar* _tmp8_;
	g_return_val_if_fail (midasi != NULL, NULL);
	g_return_val_if_fail (text != NULL, NULL);
	self = (SkkCandidate*) g_object_new (object_type, NULL);
	_tmp0_ = midasi;
	skk_candidate_set_midasi (self, _tmp0_);
	_tmp1_ = okuri;
	skk_candidate_set_okuri (self, _tmp1_);
	_tmp2_ = text;
	skk_candidate_set_text (self, _tmp2_);
	_tmp3_ = annotation;
	skk_candidate_set_annotation (self, _tmp3_);
	_tmp5_ = output;
	if (_tmp5_ == NULL) {
		const gchar* _tmp6_;
		_tmp6_ = text;
		_tmp4_ = _tmp6_;
	} else {
		const gchar* _tmp7_;
		_tmp7_ = output;
		_tmp4_ = _tmp7_;
	}
	_tmp8_ = _tmp4_;
	skk_candidate_set_output (self, _tmp8_);
	return self;
}


SkkCandidate* skk_candidate_new (const gchar* midasi, gboolean okuri, const gchar* text, const gchar* annotation, const gchar* output) {
	return skk_candidate_construct (SKK_TYPE_CANDIDATE, midasi, okuri, text, annotation, output);
}


const gchar* skk_candidate_get_midasi (SkkCandidate* self) {
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_midasi;
	result = _tmp0_;
	return result;
}


static void skk_candidate_set_midasi (SkkCandidate* self, const gchar* value) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_midasi);
	self->priv->_midasi = _tmp1_;
	g_object_notify ((GObject *) self, "midasi");
}


gboolean skk_candidate_get_okuri (SkkCandidate* self) {
	gboolean result;
	gboolean _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_okuri;
	result = _tmp0_;
	return result;
}


static void skk_candidate_set_okuri (SkkCandidate* self, gboolean value) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_okuri = _tmp0_;
	g_object_notify ((GObject *) self, "okuri");
}


const gchar* skk_candidate_get_text (SkkCandidate* self) {
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_text;
	result = _tmp0_;
	return result;
}


void skk_candidate_set_text (SkkCandidate* self, const gchar* value) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_text);
	self->priv->_text = _tmp1_;
	g_object_notify ((GObject *) self, "text");
}


const gchar* skk_candidate_get_annotation (SkkCandidate* self) {
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_annotation;
	result = _tmp0_;
	return result;
}


void skk_candidate_set_annotation (SkkCandidate* self, const gchar* value) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_annotation);
	self->priv->_annotation = _tmp1_;
	g_object_notify ((GObject *) self, "annotation");
}


const gchar* skk_candidate_get_output (SkkCandidate* self) {
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_output;
	result = _tmp0_;
	return result;
}


void skk_candidate_set_output (SkkCandidate* self, const gchar* value) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_output);
	self->priv->_output = _tmp1_;
	g_object_notify ((GObject *) self, "output");
}


static void skk_candidate_class_init (SkkCandidateClass * klass) {
	skk_candidate_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (SkkCandidatePrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_skk_candidate_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_skk_candidate_set_property;
	G_OBJECT_CLASS (klass)->finalize = skk_candidate_finalize;
	/**
	         * Midasi word which generated this candidate.
	         */
	g_object_class_install_property (G_OBJECT_CLASS (klass), SKK_CANDIDATE_MIDASI, g_param_spec_string ("midasi", "midasi", "midasi", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	/**
	         * Flag to indicate whether this candidate is generated as a
	         * result of okuri-ari conversion.
	         */
	g_object_class_install_property (G_OBJECT_CLASS (klass), SKK_CANDIDATE_OKURI, g_param_spec_boolean ("okuri", "okuri", "okuri", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	/**
	         * Base string value of the candidate.
	         */
	g_object_class_install_property (G_OBJECT_CLASS (klass), SKK_CANDIDATE_TEXT, g_param_spec_string ("text", "text", "text", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	/**
	         * Optional annotation text associated with the candidate.
	         */
	g_object_class_install_property (G_OBJECT_CLASS (klass), SKK_CANDIDATE_ANNOTATION, g_param_spec_string ("annotation", "annotation", "annotation", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	/**
	         * Output string shown instead of text.
	         *
	         * This is particularly useful to display a candidate of
	         * numeric conversion.
	         */
	g_object_class_install_property (G_OBJECT_CLASS (klass), SKK_CANDIDATE_OUTPUT, g_param_spec_string ("output", "output", "output", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void skk_candidate_instance_init (SkkCandidate * self) {
	self->priv = SKK_CANDIDATE_GET_PRIVATE (self);
}


static void skk_candidate_finalize (GObject* obj) {
	SkkCandidate * self;
	self = SKK_CANDIDATE (obj);
	_g_free0 (self->priv->_midasi);
	_g_free0 (self->priv->_text);
	_g_free0 (self->priv->_annotation);
	_g_free0 (self->priv->_output);
	G_OBJECT_CLASS (skk_candidate_parent_class)->finalize (obj);
}


/**
     * Object representing a candidate in dictionaries.
     */
GType skk_candidate_get_type (void) {
	static volatile gsize skk_candidate_type_id__volatile = 0;
	if (g_once_init_enter (&skk_candidate_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SkkCandidateClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) skk_candidate_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SkkCandidate), 0, (GInstanceInitFunc) skk_candidate_instance_init, NULL };
		GType skk_candidate_type_id;
		skk_candidate_type_id = g_type_register_static (G_TYPE_OBJECT, "SkkCandidate", &g_define_type_info, 0);
		g_once_init_leave (&skk_candidate_type_id__volatile, skk_candidate_type_id);
	}
	return skk_candidate_type_id__volatile;
}


static void _vala_skk_candidate_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	SkkCandidate * self;
	self = SKK_CANDIDATE (object);
	switch (property_id) {
		case SKK_CANDIDATE_MIDASI:
		g_value_set_string (value, skk_candidate_get_midasi (self));
		break;
		case SKK_CANDIDATE_OKURI:
		g_value_set_boolean (value, skk_candidate_get_okuri (self));
		break;
		case SKK_CANDIDATE_TEXT:
		g_value_set_string (value, skk_candidate_get_text (self));
		break;
		case SKK_CANDIDATE_ANNOTATION:
		g_value_set_string (value, skk_candidate_get_annotation (self));
		break;
		case SKK_CANDIDATE_OUTPUT:
		g_value_set_string (value, skk_candidate_get_output (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_skk_candidate_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	SkkCandidate * self;
	self = SKK_CANDIDATE (object);
	switch (property_id) {
		case SKK_CANDIDATE_MIDASI:
		skk_candidate_set_midasi (self, g_value_get_string (value));
		break;
		case SKK_CANDIDATE_OKURI:
		skk_candidate_set_okuri (self, g_value_get_boolean (value));
		break;
		case SKK_CANDIDATE_TEXT:
		skk_candidate_set_text (self, g_value_get_string (value));
		break;
		case SKK_CANDIDATE_ANNOTATION:
		skk_candidate_set_annotation (self, g_value_get_string (value));
		break;
		case SKK_CANDIDATE_OUTPUT:
		skk_candidate_set_output (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



