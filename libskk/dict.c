/* dict.c generated by valac 0.14.0, the Vala compiler
 * generated from dict.vala, do not modify */

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
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define SKK_TYPE_EMPTY_DICT (skk_empty_dict_get_type ())
#define SKK_EMPTY_DICT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SKK_TYPE_EMPTY_DICT, SkkEmptyDict))
#define SKK_EMPTY_DICT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SKK_TYPE_EMPTY_DICT, SkkEmptyDictClass))
#define SKK_IS_EMPTY_DICT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SKK_TYPE_EMPTY_DICT))
#define SKK_IS_EMPTY_DICT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SKK_TYPE_EMPTY_DICT))
#define SKK_EMPTY_DICT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SKK_TYPE_EMPTY_DICT, SkkEmptyDictClass))

typedef struct _SkkEmptyDict SkkEmptyDict;
typedef struct _SkkEmptyDictClass SkkEmptyDictClass;
typedef struct _SkkEmptyDictPrivate SkkEmptyDictPrivate;

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

struct _SkkEmptyDict {
	SkkDict parent_instance;
	SkkEmptyDictPrivate * priv;
};

struct _SkkEmptyDictClass {
	SkkDictClass parent_class;
};

typedef enum  {
	SKK_SKK_DICT_ERROR_NOT_READABLE,
	SKK_SKK_DICT_ERROR_MALFORMED_INPUT
} SkkSkkDictError;
#define SKK_SKK_DICT_ERROR skk_skk_dict_error_quark ()

static gpointer skk_dict_parent_class = NULL;
static gpointer skk_empty_dict_parent_class = NULL;

GType skk_dict_get_type (void) G_GNUC_CONST;
GType skk_candidate_get_type (void) G_GNUC_CONST;
enum  {
	SKK_DICT_DUMMY_PROPERTY,
	SKK_DICT_READ_ONLY
};
SkkCandidate** skk_dict_split_candidates (SkkDict* self, const gchar* midasi, gboolean okuri, const gchar* line, int* result_length1);
SkkCandidate* skk_candidate_new (const gchar* midasi, gboolean okuri, const gchar* text, const gchar* annotation, const gchar* output);
SkkCandidate* skk_candidate_construct (GType object_type, const gchar* midasi, gboolean okuri, const gchar* text, const gchar* annotation, const gchar* output);
gchar* skk_dict_join_candidates (SkkDict* self, SkkCandidate** candidates, int candidates_length1);
gchar* skk_candidate_to_string (SkkCandidate* self);
void skk_dict_reload (SkkDict* self, GError** error);
static void skk_dict_real_reload (SkkDict* self, GError** error);
SkkCandidate** skk_dict_lookup (SkkDict* self, const gchar* midasi, gboolean okuri, int* result_length1);
static SkkCandidate** skk_dict_real_lookup (SkkDict* self, const gchar* midasi, gboolean okuri, int* result_length1);
gchar** skk_dict_complete (SkkDict* self, const gchar* midasi, int* result_length1);
static gchar** skk_dict_real_complete (SkkDict* self, const gchar* midasi, int* result_length1);
gboolean skk_dict_select_candidate (SkkDict* self, SkkCandidate* candidate);
static gboolean skk_dict_real_select_candidate (SkkDict* self, SkkCandidate* candidate);
gboolean skk_dict_purge_candidate (SkkDict* self, SkkCandidate* candidate);
static gboolean skk_dict_real_purge_candidate (SkkDict* self, SkkCandidate* candidate);
void skk_dict_save (SkkDict* self, GError** error);
static void skk_dict_real_save (SkkDict* self, GError** error);
SkkDict* skk_dict_construct (GType object_type);
gboolean skk_dict_get_read_only (SkkDict* self);
static void _vala_skk_dict_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
GType skk_empty_dict_get_type (void) G_GNUC_CONST;
enum  {
	SKK_EMPTY_DICT_DUMMY_PROPERTY,
	SKK_EMPTY_DICT_READ_ONLY
};
static void skk_empty_dict_real_reload (SkkDict* base, GError** error);
static SkkCandidate** skk_empty_dict_real_lookup (SkkDict* base, const gchar* midasi, gboolean okuri, int* result_length1);
static gchar** skk_empty_dict_real_complete (SkkDict* base, const gchar* midasi, int* result_length1);
SkkEmptyDict* skk_empty_dict_new (void);
SkkEmptyDict* skk_empty_dict_construct (GType object_type);
static void _vala_skk_empty_dict_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
GQuark skk_skk_dict_error_quark (void);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


/**
         * Parse a line consisting of candidates separated by "/".
         *
         * @param line a line consisting of candidates
         * @return an array of Candidates
         */
static gchar* string_strip (const gchar* self) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	gchar* _result_;
	const gchar* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup (self);
	_result_ = _tmp0_;
	_tmp1_ = _result_;
	g_strstrip (_tmp1_);
	result = _result_;
	return result;
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


SkkCandidate** skk_dict_split_candidates (SkkDict* self, const gchar* midasi, gboolean okuri, const gchar* line, int* result_length1) {
	SkkCandidate** result = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_;
	gchar** _tmp5_;
	gchar** _tmp6_ = NULL;
	gchar** _tmp7_;
	gint _tmp7__length1;
	gchar** strv;
	gint strv_length1;
	gint _strv_size_;
	gchar** _tmp8_;
	gint _tmp8__length1;
	SkkCandidate** _tmp9_ = NULL;
	SkkCandidate** candidates;
	gint candidates_length1;
	gint _candidates_size_;
	SkkCandidate** _tmp39_;
	gint _tmp39__length1;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (midasi != NULL, NULL);
	g_return_val_if_fail (line != NULL, NULL);
	_tmp0_ = line;
	_tmp1_ = string_strip (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = string_slice (_tmp2_, (glong) 1, (glong) (-1));
	_tmp4_ = _tmp3_;
	_tmp6_ = _tmp5_ = g_strsplit (_tmp4_, "/", 0);
	_tmp7_ = _tmp6_;
	_tmp7__length1 = _vala_array_length (_tmp5_);
	_g_free0 (_tmp4_);
	_g_free0 (_tmp2_);
	strv = _tmp7_;
	strv_length1 = _tmp7__length1;
	_strv_size_ = strv_length1;
	_tmp8_ = strv;
	_tmp8__length1 = strv_length1;
	_tmp9_ = g_new0 (SkkCandidate*, _tmp8__length1 + 1);
	candidates = _tmp9_;
	candidates_length1 = _tmp8__length1;
	_candidates_size_ = candidates_length1;
	{
		gint i;
		i = 0;
		{
			gboolean _tmp10_;
			_tmp10_ = TRUE;
			while (TRUE) {
				gboolean _tmp11_;
				gint _tmp13_;
				gchar** _tmp14_;
				gint _tmp14__length1;
				gchar** _tmp15_;
				gint _tmp15__length1;
				gint _tmp16_;
				const gchar* _tmp17_;
				gchar** _tmp18_;
				gchar** _tmp19_ = NULL;
				gchar** text_annotation;
				gint text_annotation_length1;
				gint _text_annotation_size_;
				gchar* text = NULL;
				gchar* annotation = NULL;
				gchar** _tmp20_;
				gint _tmp20__length1;
				SkkCandidate** _tmp31_;
				gint _tmp31__length1;
				gint _tmp32_;
				const gchar* _tmp33_;
				gboolean _tmp34_;
				const gchar* _tmp35_;
				const gchar* _tmp36_;
				SkkCandidate* _tmp37_;
				SkkCandidate* _tmp38_;
				_tmp11_ = _tmp10_;
				if (!_tmp11_) {
					gint _tmp12_;
					_tmp12_ = i;
					i = _tmp12_ + 1;
				}
				_tmp10_ = FALSE;
				_tmp13_ = i;
				_tmp14_ = strv;
				_tmp14__length1 = strv_length1;
				if (!(_tmp13_ < _tmp14__length1)) {
					break;
				}
				_tmp15_ = strv;
				_tmp15__length1 = strv_length1;
				_tmp16_ = i;
				_tmp17_ = _tmp15_[_tmp16_];
				_tmp19_ = _tmp18_ = g_strsplit (_tmp17_, ";", 2);
				text_annotation = _tmp19_;
				text_annotation_length1 = _vala_array_length (_tmp18_);
				_text_annotation_size_ = text_annotation_length1;
				_tmp20_ = text_annotation;
				_tmp20__length1 = text_annotation_length1;
				if (_tmp20__length1 == 2) {
					gchar** _tmp21_;
					gint _tmp21__length1;
					const gchar* _tmp22_;
					gchar* _tmp23_;
					gchar** _tmp24_;
					gint _tmp24__length1;
					const gchar* _tmp25_;
					gchar* _tmp26_;
					_tmp21_ = text_annotation;
					_tmp21__length1 = text_annotation_length1;
					_tmp22_ = _tmp21_[0];
					_tmp23_ = g_strdup (_tmp22_);
					_g_free0 (text);
					text = _tmp23_;
					_tmp24_ = text_annotation;
					_tmp24__length1 = text_annotation_length1;
					_tmp25_ = _tmp24_[1];
					_tmp26_ = g_strdup (_tmp25_);
					_g_free0 (annotation);
					annotation = _tmp26_;
				} else {
					gchar** _tmp27_;
					gint _tmp27__length1;
					gint _tmp28_;
					const gchar* _tmp29_;
					gchar* _tmp30_;
					_tmp27_ = strv;
					_tmp27__length1 = strv_length1;
					_tmp28_ = i;
					_tmp29_ = _tmp27_[_tmp28_];
					_tmp30_ = g_strdup (_tmp29_);
					_g_free0 (text);
					text = _tmp30_;
					_g_free0 (annotation);
					annotation = NULL;
				}
				_tmp31_ = candidates;
				_tmp31__length1 = candidates_length1;
				_tmp32_ = i;
				_tmp33_ = midasi;
				_tmp34_ = okuri;
				_tmp35_ = text;
				_tmp36_ = annotation;
				_tmp37_ = skk_candidate_new (_tmp33_, _tmp34_, _tmp35_, _tmp36_, NULL);
				_g_object_unref0 (_tmp31_[_tmp32_]);
				_tmp31_[_tmp32_] = _tmp37_;
				_tmp38_ = _tmp31_[_tmp32_];
				_g_free0 (annotation);
				_g_free0 (text);
				text_annotation = (_vala_array_free (text_annotation, text_annotation_length1, (GDestroyNotify) g_free), NULL);
			}
		}
	}
	_tmp39_ = candidates;
	_tmp39__length1 = candidates_length1;
	if (result_length1) {
		*result_length1 = _tmp39__length1;
	}
	result = _tmp39_;
	strv = (_vala_array_free (strv, strv_length1, (GDestroyNotify) g_free), NULL);
	return result;
}


/**
         * Format an array of Candidates to be saved in a dictionary file.
         *
         * @param candidates an array of Candidate
         * @return a string
         */
gchar* skk_dict_join_candidates (SkkDict* self, SkkCandidate** candidates, int candidates_length1) {
	gchar* result = NULL;
	SkkCandidate** _tmp0_;
	gint _tmp0__length1;
	gchar** _tmp1_ = NULL;
	gchar** strv;
	gint strv_length1;
	gint _strv_size_;
	gchar** _tmp14_;
	gint _tmp14__length1;
	gchar* _tmp15_ = NULL;
	gchar* _tmp16_;
	gchar* _tmp17_;
	gchar* _tmp18_;
	gchar* _tmp19_;
	gchar* _tmp20_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = candidates;
	_tmp0__length1 = candidates_length1;
	_tmp1_ = g_new0 (gchar*, _tmp0__length1 + 1);
	strv = _tmp1_;
	strv_length1 = _tmp0__length1;
	_strv_size_ = strv_length1;
	{
		gint i;
		i = 0;
		{
			gboolean _tmp2_;
			_tmp2_ = TRUE;
			while (TRUE) {
				gboolean _tmp3_;
				gint _tmp5_;
				SkkCandidate** _tmp6_;
				gint _tmp6__length1;
				gchar** _tmp7_;
				gint _tmp7__length1;
				gint _tmp8_;
				SkkCandidate** _tmp9_;
				gint _tmp9__length1;
				gint _tmp10_;
				SkkCandidate* _tmp11_;
				gchar* _tmp12_ = NULL;
				gchar* _tmp13_;
				_tmp3_ = _tmp2_;
				if (!_tmp3_) {
					gint _tmp4_;
					_tmp4_ = i;
					i = _tmp4_ + 1;
				}
				_tmp2_ = FALSE;
				_tmp5_ = i;
				_tmp6_ = candidates;
				_tmp6__length1 = candidates_length1;
				if (!(_tmp5_ < _tmp6__length1)) {
					break;
				}
				_tmp7_ = strv;
				_tmp7__length1 = strv_length1;
				_tmp8_ = i;
				_tmp9_ = candidates;
				_tmp9__length1 = candidates_length1;
				_tmp10_ = i;
				_tmp11_ = _tmp9_[_tmp10_];
				_tmp12_ = skk_candidate_to_string (_tmp11_);
				_g_free0 (_tmp7_[_tmp8_]);
				_tmp7_[_tmp8_] = _tmp12_;
				_tmp13_ = _tmp7_[_tmp8_];
			}
		}
	}
	_tmp14_ = strv;
	_tmp14__length1 = strv_length1;
	_tmp15_ = g_strjoinv ("/", _tmp14_);
	_tmp16_ = _tmp15_;
	_tmp17_ = g_strconcat ("/", _tmp16_, NULL);
	_tmp18_ = _tmp17_;
	_tmp19_ = g_strconcat (_tmp18_, "/", NULL);
	_tmp20_ = _tmp19_;
	_g_free0 (_tmp18_);
	_g_free0 (_tmp16_);
	result = _tmp20_;
	strv = (_vala_array_free (strv, strv_length1, (GDestroyNotify) g_free), NULL);
	return result;
}


/**
         * Reload the dictionary.
         *
         * @throws GLib.Error when reading the dictionary failed.
         */
static void skk_dict_real_reload (SkkDict* self, GError** error) {
	g_critical ("Type `%s' does not implement abstract method `skk_dict_reload'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void skk_dict_reload (SkkDict* self, GError** error) {
	g_return_if_fail (self != NULL);
	SKK_DICT_GET_CLASS (self)->reload (self, error);
}


/**
         * Lookup candidates in the dictionary.
         *
         * @param midasi a midasi (title) string to lookup
         * @param okuri whether to search okuri-ari entries or
         * okuri-nasi entries
         *
         * @return an array of Candidate
         */
static SkkCandidate** skk_dict_real_lookup (SkkDict* self, const gchar* midasi, gboolean okuri, int* result_length1) {
	g_critical ("Type `%s' does not implement abstract method `skk_dict_lookup'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


SkkCandidate** skk_dict_lookup (SkkDict* self, const gchar* midasi, gboolean okuri, int* result_length1) {
	g_return_val_if_fail (self != NULL, NULL);
	return SKK_DICT_GET_CLASS (self)->lookup (self, midasi, okuri, result_length1);
}


/**
         * Return an array of strings which matches midasi.
         *
         * @param midasi a midasi (title) string to lookup
         *
         * @return an array of strings
         */
static gchar** skk_dict_real_complete (SkkDict* self, const gchar* midasi, int* result_length1) {
	g_critical ("Type `%s' does not implement abstract method `skk_dict_complete'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}


gchar** skk_dict_complete (SkkDict* self, const gchar* midasi, int* result_length1) {
	g_return_val_if_fail (self != NULL, NULL);
	return SKK_DICT_GET_CLASS (self)->complete (self, midasi, result_length1);
}


/**
         * Select a candidate in the dictionary.
         *
         * @param candidate an Candidate
         *
         * @return `true` if the dictionary is modified, `false` otherwise.
         */
static gboolean skk_dict_real_select_candidate (SkkDict* self, SkkCandidate* candidate) {
	gboolean result = FALSE;
	g_return_val_if_fail (candidate != NULL, FALSE);
	result = FALSE;
	return result;
}


gboolean skk_dict_select_candidate (SkkDict* self, SkkCandidate* candidate) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SKK_DICT_GET_CLASS (self)->select_candidate (self, candidate);
}


/**
         * Purge a candidate in the dictionary.
         *
         * @param candidate an Candidate
         *
         * @return `true` if the dictionary is modified, `false` otherwise.
         */
static gboolean skk_dict_real_purge_candidate (SkkDict* self, SkkCandidate* candidate) {
	gboolean result = FALSE;
	g_return_val_if_fail (candidate != NULL, FALSE);
	result = FALSE;
	return result;
}


gboolean skk_dict_purge_candidate (SkkDict* self, SkkCandidate* candidate) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SKK_DICT_GET_CLASS (self)->purge_candidate (self, candidate);
}


/**
         * Save the dictionary on disk.
         *
         * @throws GLib.Error if the dictionary cannot be saved.
         */
static void skk_dict_real_save (SkkDict* self, GError** error) {
}


void skk_dict_save (SkkDict* self, GError** error) {
	g_return_if_fail (self != NULL);
	SKK_DICT_GET_CLASS (self)->save (self, error);
}


SkkDict* skk_dict_construct (GType object_type) {
	SkkDict * self = NULL;
	self = (SkkDict*) g_object_new (object_type, NULL);
	return self;
}


gboolean skk_dict_get_read_only (SkkDict* self) {
	g_return_val_if_fail (self != NULL, FALSE);
	return SKK_DICT_GET_CLASS (self)->get_read_only (self);
}


static void skk_dict_class_init (SkkDictClass * klass) {
	skk_dict_parent_class = g_type_class_peek_parent (klass);
	SKK_DICT_CLASS (klass)->reload = skk_dict_real_reload;
	SKK_DICT_CLASS (klass)->lookup = skk_dict_real_lookup;
	SKK_DICT_CLASS (klass)->complete = skk_dict_real_complete;
	SKK_DICT_CLASS (klass)->select_candidate = skk_dict_real_select_candidate;
	SKK_DICT_CLASS (klass)->purge_candidate = skk_dict_real_purge_candidate;
	SKK_DICT_CLASS (klass)->save = skk_dict_real_save;
	G_OBJECT_CLASS (klass)->get_property = _vala_skk_dict_get_property;
	/**
	         * Flag to indicate whether the dictionary is read only.
	         */
	g_object_class_install_property (G_OBJECT_CLASS (klass), SKK_DICT_READ_ONLY, g_param_spec_boolean ("read-only", "read-only", "read-only", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void skk_dict_instance_init (SkkDict * self) {
}


/**
     * Base abstract class of dictionaries.
     */
GType skk_dict_get_type (void) {
	static volatile gsize skk_dict_type_id__volatile = 0;
	if (g_once_init_enter (&skk_dict_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SkkDictClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) skk_dict_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SkkDict), 0, (GInstanceInitFunc) skk_dict_instance_init, NULL };
		GType skk_dict_type_id;
		skk_dict_type_id = g_type_register_static (G_TYPE_OBJECT, "SkkDict", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&skk_dict_type_id__volatile, skk_dict_type_id);
	}
	return skk_dict_type_id__volatile;
}


static void _vala_skk_dict_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	SkkDict * self;
	self = SKK_DICT (object);
	switch (property_id) {
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


/**
         * {@inheritDoc}
         */
static void skk_empty_dict_real_reload (SkkDict* base, GError** error) {
	SkkEmptyDict * self;
	self = (SkkEmptyDict*) base;
}


/**
         * {@inheritDoc}
         */
static SkkCandidate** skk_empty_dict_real_lookup (SkkDict* base, const gchar* midasi, gboolean okuri, int* result_length1) {
	SkkEmptyDict * self;
	SkkCandidate** result = NULL;
	SkkCandidate** _tmp0_ = NULL;
	SkkCandidate** _tmp1_;
	gint _tmp1__length1;
	self = (SkkEmptyDict*) base;
	g_return_val_if_fail (midasi != NULL, NULL);
	_tmp0_ = g_new0 (SkkCandidate*, 0 + 1);
	_tmp1_ = _tmp0_;
	_tmp1__length1 = 0;
	if (result_length1) {
		*result_length1 = _tmp1__length1;
	}
	result = _tmp1_;
	return result;
}


/**
         * {@inheritDoc}
         */
static gchar** skk_empty_dict_real_complete (SkkDict* base, const gchar* midasi, int* result_length1) {
	SkkEmptyDict * self;
	gchar** result = NULL;
	gchar** _tmp0_ = NULL;
	gchar** _tmp1_;
	gint _tmp1__length1;
	self = (SkkEmptyDict*) base;
	g_return_val_if_fail (midasi != NULL, NULL);
	_tmp0_ = g_new0 (gchar*, 0 + 1);
	_tmp1_ = _tmp0_;
	_tmp1__length1 = 0;
	if (result_length1) {
		*result_length1 = _tmp1__length1;
	}
	result = _tmp1_;
	return result;
}


SkkEmptyDict* skk_empty_dict_construct (GType object_type) {
	SkkEmptyDict * self = NULL;
	self = (SkkEmptyDict*) skk_dict_construct (object_type);
	return self;
}


SkkEmptyDict* skk_empty_dict_new (void) {
	return skk_empty_dict_construct (SKK_TYPE_EMPTY_DICT);
}


static gboolean skk_empty_dict_real_get_read_only (SkkDict* base) {
	gboolean result;
	SkkEmptyDict* self;
	self = (SkkEmptyDict*) base;
	result = TRUE;
	return result;
}


static void skk_empty_dict_class_init (SkkEmptyDictClass * klass) {
	skk_empty_dict_parent_class = g_type_class_peek_parent (klass);
	SKK_DICT_CLASS (klass)->reload = skk_empty_dict_real_reload;
	SKK_DICT_CLASS (klass)->lookup = skk_empty_dict_real_lookup;
	SKK_DICT_CLASS (klass)->complete = skk_empty_dict_real_complete;
	SKK_DICT_CLASS (klass)->get_read_only = skk_empty_dict_real_get_read_only;
	G_OBJECT_CLASS (klass)->get_property = _vala_skk_empty_dict_get_property;
	/**
	         * {@inheritDoc}
	         */
	g_object_class_override_property (G_OBJECT_CLASS (klass), SKK_EMPTY_DICT_READ_ONLY, "read-only");
}


static void skk_empty_dict_instance_init (SkkEmptyDict * self) {
}


/**
     * Null implementation of Dict.
     */
GType skk_empty_dict_get_type (void) {
	static volatile gsize skk_empty_dict_type_id__volatile = 0;
	if (g_once_init_enter (&skk_empty_dict_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SkkEmptyDictClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) skk_empty_dict_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SkkEmptyDict), 0, (GInstanceInitFunc) skk_empty_dict_instance_init, NULL };
		GType skk_empty_dict_type_id;
		skk_empty_dict_type_id = g_type_register_static (SKK_TYPE_DICT, "SkkEmptyDict", &g_define_type_info, 0);
		g_once_init_leave (&skk_empty_dict_type_id__volatile, skk_empty_dict_type_id);
	}
	return skk_empty_dict_type_id__volatile;
}


static void _vala_skk_empty_dict_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	SkkEmptyDict * self;
	self = SKK_EMPTY_DICT (object);
	switch (property_id) {
		case SKK_EMPTY_DICT_READ_ONLY:
		g_value_set_boolean (value, skk_dict_get_read_only ((SkkDict*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


GQuark skk_skk_dict_error_quark (void) {
	return g_quark_from_static_string ("skk_skk_dict_error-quark");
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
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



