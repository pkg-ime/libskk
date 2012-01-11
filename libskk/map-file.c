/* map-file.c generated by valac 0.14.0, the Vala compiler
 * generated from map-file.vala, do not modify */

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
#include <json-glib/json-glib.h>
#include <glib/gstdio.h>


#define SKK_TYPE_MAP_FILE (skk_map_file_get_type ())
#define SKK_MAP_FILE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SKK_TYPE_MAP_FILE, SkkMapFile))
#define SKK_MAP_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SKK_TYPE_MAP_FILE, SkkMapFileClass))
#define SKK_IS_MAP_FILE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SKK_TYPE_MAP_FILE))
#define SKK_IS_MAP_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SKK_TYPE_MAP_FILE))
#define SKK_MAP_FILE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SKK_TYPE_MAP_FILE, SkkMapFileClass))

typedef struct _SkkMapFile SkkMapFile;
typedef struct _SkkMapFileClass SkkMapFileClass;
typedef struct _SkkMapFilePrivate SkkMapFilePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define __vala_JsonNode_free0(var) ((var == NULL) ? NULL : (var = (_vala_JsonNode_free (var), NULL)))
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))

#define SKK_TYPE_RULE_METADATA (skk_rule_metadata_get_type ())
typedef struct _SkkRuleMetadata SkkRuleMetadata;
#define _skk_rule_metadata_free0(var) ((var == NULL) ? NULL : (var = (skk_rule_metadata_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define __vala_JsonObject_free0(var) ((var == NULL) ? NULL : (var = (_vala_JsonObject_free (var), NULL)))
#define __vala_JsonArray_free0(var) ((var == NULL) ? NULL : (var = (_vala_JsonArray_free (var), NULL)))

struct _SkkMapFile {
	GObject parent_instance;
	SkkMapFilePrivate * priv;
};

struct _SkkMapFileClass {
	GObjectClass parent_class;
};

struct _SkkMapFilePrivate {
	GeeMap* maps;
};

typedef enum  {
	SKK_RULE_PARSE_ERROR_FAILED
} SkkRuleParseError;
#define SKK_RULE_PARSE_ERROR skk_rule_parse_error_quark ()
struct _SkkRuleMetadata {
	gchar* base_dir;
	gchar* name;
	gchar* label;
	gchar* description;
	gchar* filter;
};


static gpointer skk_map_file_parent_class = NULL;

GType skk_map_file_get_type (void) G_GNUC_CONST;
#define SKK_MAP_FILE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SKK_TYPE_MAP_FILE, SkkMapFilePrivate))
enum  {
	SKK_MAP_FILE_DUMMY_PROPERTY
};
static void skk_map_file_load_map (SkkMapFile* self, GeeMap* map, JsonObject* object);
static JsonNode* _vala_JsonNode_copy (JsonNode* self);
static void _vala_JsonNode_free (JsonNode* self);
GQuark skk_rule_parse_error_quark (void);
static void skk_map_file_load (SkkMapFile* self, const gchar* rule, const gchar* type, const gchar* name, GeeSet* included, GError** error);
GType skk_rule_metadata_get_type (void) G_GNUC_CONST;
SkkRuleMetadata* skk_rule_metadata_dup (const SkkRuleMetadata* self);
void skk_rule_metadata_free (SkkRuleMetadata* self);
void skk_rule_metadata_copy (const SkkRuleMetadata* self, SkkRuleMetadata* dest);
void skk_rule_metadata_destroy (SkkRuleMetadata* self);
SkkRuleMetadata* skk_rule_find_rule (const gchar* name);
static JsonObject* _vala_JsonObject_copy (JsonObject* self);
static void _vala_JsonObject_free (JsonObject* self);
static JsonArray* _vala_JsonArray_copy (JsonArray* self);
static void _vala_JsonArray_free (JsonArray* self);
SkkMapFile* skk_map_file_construct (GType object_type, const gchar* rule, const gchar* type, const gchar* name, GError** error);
gboolean skk_map_file_has_map (SkkMapFile* self, const gchar* name);
GeeMap* skk_map_file_get (SkkMapFile* self, const gchar* name);
static void skk_map_file_finalize (GObject* obj);


static JsonNode* _vala_JsonNode_copy (JsonNode* self) {
	return g_boxed_copy (json_node_get_type (), self);
}


static gpointer __vala_JsonNode_copy0 (gpointer self) {
	return self ? _vala_JsonNode_copy (self) : NULL;
}


static void _vala_JsonNode_free (JsonNode* self) {
	g_boxed_free (json_node_get_type (), self);
}


static void skk_map_file_load_map (SkkMapFile* self, GeeMap* map, JsonObject* object) {
	JsonObject* _tmp0_;
	GList* _tmp1_ = NULL;
	GList* keys;
	GList* _tmp2_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (map != NULL);
	g_return_if_fail (object != NULL);
	_tmp0_ = object;
	_tmp1_ = json_object_get_members (_tmp0_);
	keys = _tmp1_;
	_tmp2_ = keys;
	{
		GList* key_collection = NULL;
		GList* key_it = NULL;
		key_collection = _tmp2_;
		for (key_it = key_collection; key_it != NULL; key_it = key_it->next) {
			const gchar* key = NULL;
			key = (const gchar*) key_it->data;
			{
				JsonObject* _tmp3_;
				const gchar* _tmp4_;
				JsonNode* _tmp5_ = NULL;
				JsonNode* _tmp6_;
				JsonNode* value;
				JsonNode* _tmp7_;
				JsonNodeType _tmp8_ = 0;
				_tmp3_ = object;
				_tmp4_ = key;
				_tmp5_ = json_object_get_member (_tmp3_, _tmp4_);
				_tmp6_ = __vala_JsonNode_copy0 (_tmp5_);
				value = _tmp6_;
				_tmp7_ = value;
				_tmp8_ = json_node_get_node_type (_tmp7_);
				if (_tmp8_ == JSON_NODE_NULL) {
					GeeMap* _tmp9_;
					const gchar* _tmp10_;
					_tmp9_ = map;
					_tmp10_ = key;
					gee_map_unset (_tmp9_, _tmp10_, NULL);
				} else {
					GeeMap* _tmp11_;
					const gchar* _tmp12_;
					JsonNode* _tmp13_;
					_tmp11_ = map;
					_tmp12_ = key;
					_tmp13_ = value;
					gee_map_set (_tmp11_, _tmp12_, _tmp13_);
				}
				__vala_JsonNode_free0 (value);
			}
		}
	}
	_g_list_free0 (keys);
}


static JsonObject* _vala_JsonObject_copy (JsonObject* self) {
	return g_boxed_copy (json_object_get_type (), self);
}


static gpointer __vala_JsonObject_copy0 (gpointer self) {
	return self ? _vala_JsonObject_copy (self) : NULL;
}


static void _vala_JsonObject_free (JsonObject* self) {
	g_boxed_free (json_object_get_type (), self);
}


static JsonArray* _vala_JsonArray_copy (JsonArray* self) {
	return g_boxed_copy (json_array_get_type (), self);
}


static gpointer __vala_JsonArray_copy0 (gpointer self) {
	return self ? _vala_JsonArray_copy (self) : NULL;
}


static void _vala_JsonArray_free (JsonArray* self) {
	g_boxed_free (json_array_get_type (), self);
}


static gint string_index_of (const gchar* self, const gchar* needle, gint start_index) {
	gint result = 0;
	gint _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* _result_;
	gchar* _tmp3_;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (needle != NULL, 0);
	_tmp0_ = start_index;
	_tmp1_ = needle;
	_tmp2_ = strstr (((gchar*) self) + _tmp0_, (gchar*) _tmp1_);
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


static void skk_map_file_load (SkkMapFile* self, const gchar* rule, const gchar* type, const gchar* name, GeeSet* included, GError** error) {
	const gchar* _tmp0_;
	SkkRuleMetadata* _tmp1_ = NULL;
	SkkRuleMetadata* metadata;
	SkkRuleMetadata* _tmp2_;
	SkkRuleMetadata* _tmp5_;
	const gchar* _tmp6_;
	const gchar* _tmp7_;
	const gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_ = NULL;
	gchar* _tmp12_;
	gchar* filename;
	const gchar* _tmp13_;
	gboolean _tmp14_ = FALSE;
	JsonParser* _tmp17_;
	JsonParser* parser;
	JsonParser* _tmp30_;
	JsonNode* _tmp31_ = NULL;
	JsonNode* _tmp32_;
	JsonNode* root;
	JsonNode* _tmp33_;
	JsonNodeType _tmp34_ = 0;
	JsonNode* _tmp36_;
	JsonObject* _tmp37_ = NULL;
	JsonObject* _tmp38_;
	JsonObject* object;
	JsonNode* member = NULL;
	JsonObject* _tmp39_;
	gboolean _tmp40_ = FALSE;
	JsonObject* _tmp83_;
	gboolean _tmp84_ = FALSE;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (rule != NULL);
	g_return_if_fail (type != NULL);
	g_return_if_fail (name != NULL);
	g_return_if_fail (included != NULL);
	_tmp0_ = rule;
	_tmp1_ = skk_rule_find_rule (_tmp0_);
	metadata = _tmp1_;
	_tmp2_ = metadata;
	if (_tmp2_ == NULL) {
		const gchar* _tmp3_;
		GError* _tmp4_;
		_tmp3_ = rule;
		_tmp4_ = g_error_new (SKK_RULE_PARSE_ERROR, SKK_RULE_PARSE_ERROR_FAILED, "can't find rule %s", _tmp3_);
		_inner_error_ = _tmp4_;
		if (_inner_error_->domain == SKK_RULE_PARSE_ERROR) {
			g_propagate_error (error, _inner_error_);
			_skk_rule_metadata_free0 (metadata);
			return;
		} else {
			_skk_rule_metadata_free0 (metadata);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	_tmp5_ = metadata;
	_tmp6_ = (*_tmp5_).base_dir;
	_tmp7_ = type;
	_tmp8_ = name;
	_tmp9_ = g_strconcat (_tmp8_, ".json", NULL);
	_tmp10_ = _tmp9_;
	_tmp11_ = g_build_filename (_tmp6_, _tmp7_, _tmp10_, NULL);
	_tmp12_ = _tmp11_;
	_g_free0 (_tmp10_);
	filename = _tmp12_;
	_tmp13_ = filename;
	_tmp14_ = g_file_test (_tmp13_, G_FILE_TEST_EXISTS);
	if (!_tmp14_) {
		const gchar* _tmp15_;
		GError* _tmp16_;
		_tmp15_ = filename;
		_tmp16_ = g_error_new (SKK_RULE_PARSE_ERROR, SKK_RULE_PARSE_ERROR_FAILED, "no such file %s", _tmp15_);
		_inner_error_ = _tmp16_;
		if (_inner_error_->domain == SKK_RULE_PARSE_ERROR) {
			g_propagate_error (error, _inner_error_);
			_g_free0 (filename);
			_skk_rule_metadata_free0 (metadata);
			return;
		} else {
			_g_free0 (filename);
			_skk_rule_metadata_free0 (metadata);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	_tmp17_ = json_parser_new ();
	parser = _tmp17_;
	{
		JsonParser* _tmp18_;
		const gchar* _tmp19_;
		gboolean _tmp20_ = FALSE;
		gboolean _tmp21_;
		_tmp18_ = parser;
		_tmp19_ = filename;
		_tmp20_ = json_parser_load_from_file (_tmp18_, _tmp19_, &_inner_error_);
		_tmp21_ = _tmp20_;
		if (_inner_error_ != NULL) {
			goto __catch24_g_error;
		}
		if (!_tmp21_) {
			GError* _tmp22_;
			_tmp22_ = g_error_new_literal (SKK_RULE_PARSE_ERROR, SKK_RULE_PARSE_ERROR_FAILED, "");
			_inner_error_ = _tmp22_;
			goto __catch24_g_error;
		}
	}
	goto __finally24;
	__catch24_g_error:
	{
		GError* e = NULL;
		const gchar* _tmp23_;
		GError* _tmp24_;
		const gchar* _tmp25_;
		gchar* _tmp26_ = NULL;
		gchar* _tmp27_;
		GError* _tmp28_;
		GError* _tmp29_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp23_ = filename;
		_tmp24_ = e;
		_tmp25_ = _tmp24_->message;
		_tmp26_ = g_strdup_printf ("can't load %s: %s", _tmp23_, _tmp25_);
		_tmp27_ = _tmp26_;
		_tmp28_ = g_error_new_literal (SKK_RULE_PARSE_ERROR, SKK_RULE_PARSE_ERROR_FAILED, _tmp27_);
		_tmp29_ = _tmp28_;
		_g_free0 (_tmp27_);
		_inner_error_ = _tmp29_;
		_g_error_free0 (e);
		goto __finally24;
	}
	__finally24:
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == SKK_RULE_PARSE_ERROR) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (parser);
			_g_free0 (filename);
			_skk_rule_metadata_free0 (metadata);
			return;
		} else {
			_g_object_unref0 (parser);
			_g_free0 (filename);
			_skk_rule_metadata_free0 (metadata);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	_tmp30_ = parser;
	_tmp31_ = json_parser_get_root (_tmp30_);
	_tmp32_ = __vala_JsonNode_copy0 (_tmp31_);
	root = _tmp32_;
	_tmp33_ = root;
	_tmp34_ = json_node_get_node_type (_tmp33_);
	if (_tmp34_ != JSON_NODE_OBJECT) {
		GError* _tmp35_;
		_tmp35_ = g_error_new_literal (SKK_RULE_PARSE_ERROR, SKK_RULE_PARSE_ERROR_FAILED, "root element must be an object");
		_inner_error_ = _tmp35_;
		if (_inner_error_->domain == SKK_RULE_PARSE_ERROR) {
			g_propagate_error (error, _inner_error_);
			__vala_JsonNode_free0 (root);
			_g_object_unref0 (parser);
			_g_free0 (filename);
			_skk_rule_metadata_free0 (metadata);
			return;
		} else {
			__vala_JsonNode_free0 (root);
			_g_object_unref0 (parser);
			_g_free0 (filename);
			_skk_rule_metadata_free0 (metadata);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	_tmp36_ = root;
	_tmp37_ = json_node_get_object (_tmp36_);
	_tmp38_ = __vala_JsonObject_copy0 (_tmp37_);
	object = _tmp38_;
	_tmp39_ = object;
	_tmp40_ = json_object_has_member (_tmp39_, "include");
	if (_tmp40_) {
		JsonObject* _tmp41_;
		JsonNode* _tmp42_ = NULL;
		JsonNode* _tmp43_;
		JsonNode* _tmp44_;
		JsonNodeType _tmp45_ = 0;
		JsonNode* _tmp47_;
		JsonArray* _tmp48_ = NULL;
		JsonArray* _tmp49_;
		JsonArray* include;
		JsonArray* _tmp50_;
		GList* _tmp51_ = NULL;
		GList* elements;
		GList* _tmp52_;
		_tmp41_ = object;
		_tmp42_ = json_object_get_member (_tmp41_, "include");
		_tmp43_ = __vala_JsonNode_copy0 (_tmp42_);
		__vala_JsonNode_free0 (member);
		member = _tmp43_;
		_tmp44_ = member;
		_tmp45_ = json_node_get_node_type (_tmp44_);
		if (_tmp45_ != JSON_NODE_ARRAY) {
			GError* _tmp46_;
			_tmp46_ = g_error_new_literal (SKK_RULE_PARSE_ERROR, SKK_RULE_PARSE_ERROR_FAILED, "\"include\" element must be an array");
			_inner_error_ = _tmp46_;
			if (_inner_error_->domain == SKK_RULE_PARSE_ERROR) {
				g_propagate_error (error, _inner_error_);
				__vala_JsonNode_free0 (member);
				__vala_JsonObject_free0 (object);
				__vala_JsonNode_free0 (root);
				_g_object_unref0 (parser);
				_g_free0 (filename);
				_skk_rule_metadata_free0 (metadata);
				return;
			} else {
				__vala_JsonNode_free0 (member);
				__vala_JsonObject_free0 (object);
				__vala_JsonNode_free0 (root);
				_g_object_unref0 (parser);
				_g_free0 (filename);
				_skk_rule_metadata_free0 (metadata);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		}
		_tmp47_ = member;
		_tmp48_ = json_node_get_array (_tmp47_);
		_tmp49_ = __vala_JsonArray_copy0 (_tmp48_);
		include = _tmp49_;
		_tmp50_ = include;
		_tmp51_ = json_array_get_elements (_tmp50_);
		elements = _tmp51_;
		_tmp52_ = elements;
		{
			GList* element_collection = NULL;
			GList* element_it = NULL;
			element_collection = _tmp52_;
			for (element_it = element_collection; element_it != NULL; element_it = element_it->next) {
				JsonNode* element = NULL;
				element = (JsonNode*) element_it->data;
				{
					JsonNode* _tmp53_;
					const gchar* _tmp54_ = NULL;
					gchar* _tmp55_;
					gchar* parent;
					GeeSet* _tmp56_;
					const gchar* _tmp57_;
					gboolean _tmp58_ = FALSE;
					const gchar* _tmp61_;
					gint _tmp62_ = 0;
					gint index;
					gint _tmp63_;
					GeeSet* _tmp81_;
					const gchar* _tmp82_;
					_tmp53_ = element;
					_tmp54_ = json_node_get_string (_tmp53_);
					_tmp55_ = g_strdup (_tmp54_);
					parent = _tmp55_;
					_tmp56_ = included;
					_tmp57_ = parent;
					_tmp58_ = gee_collection_contains ((GeeCollection*) _tmp56_, _tmp57_);
					if (_tmp58_) {
						const gchar* _tmp59_;
						GError* _tmp60_;
						_tmp59_ = parent;
						_tmp60_ = g_error_new (SKK_RULE_PARSE_ERROR, SKK_RULE_PARSE_ERROR_FAILED, "found circular include of %s", _tmp59_);
						_inner_error_ = _tmp60_;
						if (_inner_error_->domain == SKK_RULE_PARSE_ERROR) {
							g_propagate_error (error, _inner_error_);
							_g_free0 (parent);
							_g_list_free0 (elements);
							__vala_JsonArray_free0 (include);
							__vala_JsonNode_free0 (member);
							__vala_JsonObject_free0 (object);
							__vala_JsonNode_free0 (root);
							_g_object_unref0 (parser);
							_g_free0 (filename);
							_skk_rule_metadata_free0 (metadata);
							return;
						} else {
							_g_free0 (parent);
							_g_list_free0 (elements);
							__vala_JsonArray_free0 (include);
							__vala_JsonNode_free0 (member);
							__vala_JsonObject_free0 (object);
							__vala_JsonNode_free0 (root);
							_g_object_unref0 (parser);
							_g_free0 (filename);
							_skk_rule_metadata_free0 (metadata);
							g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
							g_clear_error (&_inner_error_);
							return;
						}
					}
					_tmp61_ = parent;
					_tmp62_ = string_index_of (_tmp61_, "/", 0);
					index = _tmp62_;
					_tmp63_ = index;
					if (_tmp63_ < 0) {
						const gchar* _tmp64_;
						const gchar* _tmp65_;
						const gchar* _tmp66_;
						GeeSet* _tmp67_;
						_tmp64_ = rule;
						_tmp65_ = type;
						_tmp66_ = parent;
						_tmp67_ = included;
						skk_map_file_load (self, _tmp64_, _tmp65_, _tmp66_, _tmp67_, &_inner_error_);
						if (_inner_error_ != NULL) {
							if (_inner_error_->domain == SKK_RULE_PARSE_ERROR) {
								g_propagate_error (error, _inner_error_);
								_g_free0 (parent);
								_g_list_free0 (elements);
								__vala_JsonArray_free0 (include);
								__vala_JsonNode_free0 (member);
								__vala_JsonObject_free0 (object);
								__vala_JsonNode_free0 (root);
								_g_object_unref0 (parser);
								_g_free0 (filename);
								_skk_rule_metadata_free0 (metadata);
								return;
							} else {
								_g_free0 (parent);
								_g_list_free0 (elements);
								__vala_JsonArray_free0 (include);
								__vala_JsonNode_free0 (member);
								__vala_JsonObject_free0 (object);
								__vala_JsonNode_free0 (root);
								_g_object_unref0 (parser);
								_g_free0 (filename);
								_skk_rule_metadata_free0 (metadata);
								g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
								g_clear_error (&_inner_error_);
								return;
							}
						}
					} else {
						const gchar* _tmp68_;
						gint _tmp69_;
						gchar* _tmp70_ = NULL;
						gchar* _tmp71_;
						const gchar* _tmp72_;
						const gchar* _tmp73_;
						gint _tmp74_;
						const gchar* _tmp75_;
						gint _tmp76_;
						gint _tmp77_;
						gchar* _tmp78_ = NULL;
						gchar* _tmp79_;
						GeeSet* _tmp80_;
						_tmp68_ = parent;
						_tmp69_ = index;
						_tmp70_ = string_slice (_tmp68_, (glong) 0, (glong) _tmp69_);
						_tmp71_ = _tmp70_;
						_tmp72_ = type;
						_tmp73_ = parent;
						_tmp74_ = index;
						_tmp75_ = parent;
						_tmp76_ = strlen (_tmp75_);
						_tmp77_ = _tmp76_;
						_tmp78_ = string_slice (_tmp73_, (glong) (_tmp74_ + 1), (glong) _tmp77_);
						_tmp79_ = _tmp78_;
						_tmp80_ = included;
						skk_map_file_load (self, _tmp71_, _tmp72_, _tmp79_, _tmp80_, &_inner_error_);
						_g_free0 (_tmp79_);
						_g_free0 (_tmp71_);
						if (_inner_error_ != NULL) {
							if (_inner_error_->domain == SKK_RULE_PARSE_ERROR) {
								g_propagate_error (error, _inner_error_);
								_g_free0 (parent);
								_g_list_free0 (elements);
								__vala_JsonArray_free0 (include);
								__vala_JsonNode_free0 (member);
								__vala_JsonObject_free0 (object);
								__vala_JsonNode_free0 (root);
								_g_object_unref0 (parser);
								_g_free0 (filename);
								_skk_rule_metadata_free0 (metadata);
								return;
							} else {
								_g_free0 (parent);
								_g_list_free0 (elements);
								__vala_JsonArray_free0 (include);
								__vala_JsonNode_free0 (member);
								__vala_JsonObject_free0 (object);
								__vala_JsonNode_free0 (root);
								_g_object_unref0 (parser);
								_g_free0 (filename);
								_skk_rule_metadata_free0 (metadata);
								g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
								g_clear_error (&_inner_error_);
								return;
							}
						}
					}
					_tmp81_ = included;
					_tmp82_ = parent;
					gee_collection_add ((GeeCollection*) _tmp81_, _tmp82_);
					_g_free0 (parent);
				}
			}
		}
		_g_list_free0 (elements);
		__vala_JsonArray_free0 (include);
	}
	_tmp83_ = object;
	_tmp84_ = json_object_has_member (_tmp83_, "define");
	if (_tmp84_) {
		JsonObject* _tmp85_;
		JsonNode* _tmp86_ = NULL;
		JsonNode* _tmp87_;
		JsonNode* _tmp88_;
		JsonNodeType _tmp89_ = 0;
		JsonNode* _tmp91_;
		JsonObject* _tmp92_ = NULL;
		JsonObject* _tmp93_;
		JsonObject* define;
		JsonObject* _tmp94_;
		GList* _tmp95_ = NULL;
		GList* keys;
		GList* _tmp96_;
		_tmp85_ = object;
		_tmp86_ = json_object_get_member (_tmp85_, "define");
		_tmp87_ = __vala_JsonNode_copy0 (_tmp86_);
		__vala_JsonNode_free0 (member);
		member = _tmp87_;
		_tmp88_ = member;
		_tmp89_ = json_node_get_node_type (_tmp88_);
		if (_tmp89_ != JSON_NODE_OBJECT) {
			GError* _tmp90_;
			_tmp90_ = g_error_new_literal (SKK_RULE_PARSE_ERROR, SKK_RULE_PARSE_ERROR_FAILED, "\"define\" element must be an object");
			_inner_error_ = _tmp90_;
			if (_inner_error_->domain == SKK_RULE_PARSE_ERROR) {
				g_propagate_error (error, _inner_error_);
				__vala_JsonNode_free0 (member);
				__vala_JsonObject_free0 (object);
				__vala_JsonNode_free0 (root);
				_g_object_unref0 (parser);
				_g_free0 (filename);
				_skk_rule_metadata_free0 (metadata);
				return;
			} else {
				__vala_JsonNode_free0 (member);
				__vala_JsonObject_free0 (object);
				__vala_JsonNode_free0 (root);
				_g_object_unref0 (parser);
				_g_free0 (filename);
				_skk_rule_metadata_free0 (metadata);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		}
		_tmp91_ = member;
		_tmp92_ = json_node_get_object (_tmp91_);
		_tmp93_ = __vala_JsonObject_copy0 (_tmp92_);
		define = _tmp93_;
		_tmp94_ = define;
		_tmp95_ = json_object_get_members (_tmp94_);
		keys = _tmp95_;
		_tmp96_ = keys;
		{
			GList* key_collection = NULL;
			GList* key_it = NULL;
			key_collection = _tmp96_;
			for (key_it = key_collection; key_it != NULL; key_it = key_it->next) {
				const gchar* key = NULL;
				key = (const gchar*) key_it->data;
				{
					GeeMap* _tmp97_;
					const gchar* _tmp98_;
					gboolean _tmp99_ = FALSE;
					JsonObject* _tmp104_;
					const gchar* _tmp105_;
					JsonNode* _tmp106_ = NULL;
					JsonNode* _tmp107_;
					JsonNode* _tmp108_;
					JsonNodeType _tmp109_ = 0;
					GeeMap* _tmp111_;
					const gchar* _tmp112_;
					gpointer _tmp113_ = NULL;
					GeeMap* _tmp114_;
					JsonNode* _tmp115_;
					JsonObject* _tmp116_ = NULL;
					_tmp97_ = self->priv->maps;
					_tmp98_ = key;
					_tmp99_ = gee_map_has_key (_tmp97_, _tmp98_);
					if (!_tmp99_) {
						GeeHashMap* _tmp100_;
						GeeHashMap* map;
						GeeMap* _tmp101_;
						const gchar* _tmp102_;
						GeeHashMap* _tmp103_;
						_tmp100_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, json_node_get_type (), (GBoxedCopyFunc) _vala_JsonNode_copy, _vala_JsonNode_free, NULL, NULL, NULL);
						map = _tmp100_;
						_tmp101_ = self->priv->maps;
						_tmp102_ = key;
						_tmp103_ = map;
						gee_map_set (_tmp101_, _tmp102_, (GeeMap*) _tmp103_);
						_g_object_unref0 (map);
					}
					_tmp104_ = define;
					_tmp105_ = key;
					_tmp106_ = json_object_get_member (_tmp104_, _tmp105_);
					_tmp107_ = __vala_JsonNode_copy0 (_tmp106_);
					__vala_JsonNode_free0 (member);
					member = _tmp107_;
					_tmp108_ = member;
					_tmp109_ = json_node_get_node_type (_tmp108_);
					if (_tmp109_ != JSON_NODE_OBJECT) {
						GError* _tmp110_;
						_tmp110_ = g_error_new_literal (SKK_RULE_PARSE_ERROR, SKK_RULE_PARSE_ERROR_FAILED, "map element must be an object");
						_inner_error_ = _tmp110_;
						if (_inner_error_->domain == SKK_RULE_PARSE_ERROR) {
							g_propagate_error (error, _inner_error_);
							_g_list_free0 (keys);
							__vala_JsonObject_free0 (define);
							__vala_JsonNode_free0 (member);
							__vala_JsonObject_free0 (object);
							__vala_JsonNode_free0 (root);
							_g_object_unref0 (parser);
							_g_free0 (filename);
							_skk_rule_metadata_free0 (metadata);
							return;
						} else {
							_g_list_free0 (keys);
							__vala_JsonObject_free0 (define);
							__vala_JsonNode_free0 (member);
							__vala_JsonObject_free0 (object);
							__vala_JsonNode_free0 (root);
							_g_object_unref0 (parser);
							_g_free0 (filename);
							_skk_rule_metadata_free0 (metadata);
							g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
							g_clear_error (&_inner_error_);
							return;
						}
					}
					_tmp111_ = self->priv->maps;
					_tmp112_ = key;
					_tmp113_ = gee_map_get (_tmp111_, _tmp112_);
					_tmp114_ = (GeeMap*) _tmp113_;
					_tmp115_ = member;
					_tmp116_ = json_node_get_object (_tmp115_);
					skk_map_file_load_map (self, _tmp114_, _tmp116_);
					_g_object_unref0 (_tmp114_);
				}
			}
		}
		_g_list_free0 (keys);
		__vala_JsonObject_free0 (define);
	}
	__vala_JsonNode_free0 (member);
	__vala_JsonObject_free0 (object);
	__vala_JsonNode_free0 (root);
	_g_object_unref0 (parser);
	_g_free0 (filename);
	_skk_rule_metadata_free0 (metadata);
}


SkkMapFile* skk_map_file_construct (GType object_type, const gchar* rule, const gchar* type, const gchar* name, GError** error) {
	SkkMapFile * self = NULL;
	GeeHashSet* _tmp0_;
	GeeSet* included;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	const gchar* _tmp3_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (rule != NULL, NULL);
	g_return_val_if_fail (type != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	self = (SkkMapFile*) g_object_new (object_type, NULL);
	_tmp0_ = gee_hash_set_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL, NULL);
	included = (GeeSet*) _tmp0_;
	_tmp1_ = rule;
	_tmp2_ = type;
	_tmp3_ = name;
	skk_map_file_load (self, _tmp1_, _tmp2_, _tmp3_, included, &_inner_error_);
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == SKK_RULE_PARSE_ERROR) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (included);
			_g_object_unref0 (self);
			return NULL;
		} else {
			_g_object_unref0 (included);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_g_object_unref0 (included);
	return self;
}


gboolean skk_map_file_has_map (SkkMapFile* self, const gchar* name) {
	gboolean result = FALSE;
	GeeMap* _tmp0_;
	const gchar* _tmp1_;
	gboolean _tmp2_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (name != NULL, FALSE);
	_tmp0_ = self->priv->maps;
	_tmp1_ = name;
	_tmp2_ = gee_map_has_key (_tmp0_, _tmp1_);
	result = _tmp2_;
	return result;
}


GeeMap* skk_map_file_get (SkkMapFile* self, const gchar* name) {
	GeeMap* result = NULL;
	GeeMap* _tmp0_;
	const gchar* _tmp1_;
	gpointer _tmp2_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	_tmp0_ = self->priv->maps;
	_tmp1_ = name;
	_tmp2_ = gee_map_get (_tmp0_, _tmp1_);
	result = (GeeMap*) _tmp2_;
	return result;
}


static void skk_map_file_class_init (SkkMapFileClass * klass) {
	skk_map_file_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (SkkMapFilePrivate));
	G_OBJECT_CLASS (klass)->finalize = skk_map_file_finalize;
}


static void skk_map_file_instance_init (SkkMapFile * self) {
	GeeHashMap* _tmp0_;
	self->priv = SKK_MAP_FILE_GET_PRIVATE (self);
	_tmp0_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, GEE_TYPE_MAP, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL);
	self->priv->maps = (GeeMap*) _tmp0_;
}


static void skk_map_file_finalize (GObject* obj) {
	SkkMapFile * self;
	self = SKK_MAP_FILE (obj);
	_g_object_unref0 (self->priv->maps);
	G_OBJECT_CLASS (skk_map_file_parent_class)->finalize (obj);
}


GType skk_map_file_get_type (void) {
	static volatile gsize skk_map_file_type_id__volatile = 0;
	if (g_once_init_enter (&skk_map_file_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SkkMapFileClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) skk_map_file_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SkkMapFile), 0, (GInstanceInitFunc) skk_map_file_instance_init, NULL };
		GType skk_map_file_type_id;
		skk_map_file_type_id = g_type_register_static (G_TYPE_OBJECT, "SkkMapFile", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&skk_map_file_type_id__volatile, skk_map_file_type_id);
	}
	return skk_map_file_type_id__volatile;
}



