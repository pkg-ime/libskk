/* expr.c generated by valac 0.14.0, the Vala compiler
 * generated from expr.vala, do not modify */

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
#include <config.h>
#include <gobject/gvaluecollector.h>


#define SKK_TYPE_EXPR_NODE_TYPE (skk_expr_node_type_get_type ())

#define SKK_TYPE_EXPR_NODE (skk_expr_node_get_type ())
#define SKK_EXPR_NODE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SKK_TYPE_EXPR_NODE, SkkExprNode))
#define SKK_EXPR_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SKK_TYPE_EXPR_NODE, SkkExprNodeClass))
#define SKK_IS_EXPR_NODE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SKK_TYPE_EXPR_NODE))
#define SKK_IS_EXPR_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SKK_TYPE_EXPR_NODE))
#define SKK_EXPR_NODE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SKK_TYPE_EXPR_NODE, SkkExprNodeClass))

typedef struct _SkkExprNode SkkExprNode;
typedef struct _SkkExprNodeClass SkkExprNodeClass;
typedef struct _SkkExprNodePrivate SkkExprNodePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _SkkParamSpecExprNode SkkParamSpecExprNode;

#define SKK_TYPE_EXPR_READER (skk_expr_reader_get_type ())
#define SKK_EXPR_READER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SKK_TYPE_EXPR_READER, SkkExprReader))
#define SKK_EXPR_READER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SKK_TYPE_EXPR_READER, SkkExprReaderClass))
#define SKK_IS_EXPR_READER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SKK_TYPE_EXPR_READER))
#define SKK_IS_EXPR_READER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SKK_TYPE_EXPR_READER))
#define SKK_EXPR_READER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SKK_TYPE_EXPR_READER, SkkExprReaderClass))

typedef struct _SkkExprReader SkkExprReader;
typedef struct _SkkExprReaderClass SkkExprReaderClass;
typedef struct _SkkExprReaderPrivate SkkExprReaderPrivate;
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))
#define _skk_expr_node_unref0(var) ((var == NULL) ? NULL : (var = (skk_expr_node_unref (var), NULL)))

#define SKK_TYPE_EXPR_EVALUATOR (skk_expr_evaluator_get_type ())
#define SKK_EXPR_EVALUATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SKK_TYPE_EXPR_EVALUATOR, SkkExprEvaluator))
#define SKK_EXPR_EVALUATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SKK_TYPE_EXPR_EVALUATOR, SkkExprEvaluatorClass))
#define SKK_IS_EXPR_EVALUATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SKK_TYPE_EXPR_EVALUATOR))
#define SKK_IS_EXPR_EVALUATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SKK_TYPE_EXPR_EVALUATOR))
#define SKK_EXPR_EVALUATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SKK_TYPE_EXPR_EVALUATOR, SkkExprEvaluatorClass))

typedef struct _SkkExprEvaluator SkkExprEvaluator;
typedef struct _SkkExprEvaluatorClass SkkExprEvaluatorClass;
typedef struct _SkkExprEvaluatorPrivate SkkExprEvaluatorPrivate;
#define _g_date_time_unref0(var) ((var == NULL) ? NULL : (var = (g_date_time_unref (var), NULL)))

typedef enum  {
	SKK_EXPR_NODE_TYPE_ARRAY,
	SKK_EXPR_NODE_TYPE_SYMBOL,
	SKK_EXPR_NODE_TYPE_STRING
} SkkExprNodeType;

struct _SkkExprNode {
	GTypeInstance parent_instance;
	volatile int ref_count;
	SkkExprNodePrivate * priv;
	SkkExprNodeType type;
	GeeLinkedList* nodes;
	gchar* data;
};

struct _SkkExprNodeClass {
	GTypeClass parent_class;
	void (*finalize) (SkkExprNode *self);
};

struct _SkkParamSpecExprNode {
	GParamSpec parent_instance;
};

struct _SkkExprReader {
	GObject parent_instance;
	SkkExprReaderPrivate * priv;
};

struct _SkkExprReaderClass {
	GObjectClass parent_class;
};

struct _SkkExprEvaluator {
	GObject parent_instance;
	SkkExprEvaluatorPrivate * priv;
};

struct _SkkExprEvaluatorClass {
	GObjectClass parent_class;
};


static gpointer skk_expr_node_parent_class = NULL;
static gpointer skk_expr_reader_parent_class = NULL;
static gpointer skk_expr_evaluator_parent_class = NULL;

GType skk_expr_node_type_get_type (void) G_GNUC_CONST;
gpointer skk_expr_node_ref (gpointer instance);
void skk_expr_node_unref (gpointer instance);
GParamSpec* skk_param_spec_expr_node (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void skk_value_set_expr_node (GValue* value, gpointer v_object);
void skk_value_take_expr_node (GValue* value, gpointer v_object);
gpointer skk_value_get_expr_node (const GValue* value);
GType skk_expr_node_get_type (void) G_GNUC_CONST;
enum  {
	SKK_EXPR_NODE_DUMMY_PROPERTY
};
SkkExprNode* skk_expr_node_new (SkkExprNodeType type);
SkkExprNode* skk_expr_node_construct (GType object_type, SkkExprNodeType type);
static void skk_expr_node_finalize (SkkExprNode* obj);
GType skk_expr_reader_get_type (void) G_GNUC_CONST;
enum  {
	SKK_EXPR_READER_DUMMY_PROPERTY
};
SkkExprNode* skk_expr_reader_read_symbol (SkkExprReader* self, const gchar* expr, gint* index);
SkkExprNode* skk_expr_reader_read_string (SkkExprReader* self, const gchar* expr, gint* index);
SkkExprNode* skk_expr_reader_read_expr (SkkExprReader* self, const gchar* expr, gint* index);
SkkExprReader* skk_expr_reader_new (void);
SkkExprReader* skk_expr_reader_construct (GType object_type);
GType skk_expr_evaluator_get_type (void) G_GNUC_CONST;
enum  {
	SKK_EXPR_EVALUATOR_DUMMY_PROPERTY
};
gchar* skk_expr_evaluator_eval (SkkExprEvaluator* self, SkkExprNode* node);
SkkExprEvaluator* skk_expr_evaluator_new (void);
SkkExprEvaluator* skk_expr_evaluator_construct (GType object_type);


GType skk_expr_node_type_get_type (void) {
	static volatile gsize skk_expr_node_type_type_id__volatile = 0;
	if (g_once_init_enter (&skk_expr_node_type_type_id__volatile)) {
		static const GEnumValue values[] = {{SKK_EXPR_NODE_TYPE_ARRAY, "SKK_EXPR_NODE_TYPE_ARRAY", "array"}, {SKK_EXPR_NODE_TYPE_SYMBOL, "SKK_EXPR_NODE_TYPE_SYMBOL", "symbol"}, {SKK_EXPR_NODE_TYPE_STRING, "SKK_EXPR_NODE_TYPE_STRING", "string"}, {0, NULL, NULL}};
		GType skk_expr_node_type_type_id;
		skk_expr_node_type_type_id = g_enum_register_static ("SkkExprNodeType", values);
		g_once_init_leave (&skk_expr_node_type_type_id__volatile, skk_expr_node_type_type_id);
	}
	return skk_expr_node_type_type_id__volatile;
}


SkkExprNode* skk_expr_node_construct (GType object_type, SkkExprNodeType type) {
	SkkExprNode* self = NULL;
	SkkExprNodeType _tmp0_;
	self = (SkkExprNode*) g_type_create_instance (object_type);
	_tmp0_ = type;
	self->type = _tmp0_;
	return self;
}


SkkExprNode* skk_expr_node_new (SkkExprNodeType type) {
	return skk_expr_node_construct (SKK_TYPE_EXPR_NODE, type);
}


static void skk_value_expr_node_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void skk_value_expr_node_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		skk_expr_node_unref (value->data[0].v_pointer);
	}
}


static void skk_value_expr_node_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = skk_expr_node_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer skk_value_expr_node_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* skk_value_expr_node_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		SkkExprNode* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = skk_expr_node_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* skk_value_expr_node_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	SkkExprNode** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = skk_expr_node_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* skk_param_spec_expr_node (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	SkkParamSpecExprNode* spec;
	g_return_val_if_fail (g_type_is_a (object_type, SKK_TYPE_EXPR_NODE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer skk_value_get_expr_node (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SKK_TYPE_EXPR_NODE), NULL);
	return value->data[0].v_pointer;
}


void skk_value_set_expr_node (GValue* value, gpointer v_object) {
	SkkExprNode* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SKK_TYPE_EXPR_NODE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SKK_TYPE_EXPR_NODE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		skk_expr_node_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		skk_expr_node_unref (old);
	}
}


void skk_value_take_expr_node (GValue* value, gpointer v_object) {
	SkkExprNode* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, SKK_TYPE_EXPR_NODE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, SKK_TYPE_EXPR_NODE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		skk_expr_node_unref (old);
	}
}


static void skk_expr_node_class_init (SkkExprNodeClass * klass) {
	skk_expr_node_parent_class = g_type_class_peek_parent (klass);
	SKK_EXPR_NODE_CLASS (klass)->finalize = skk_expr_node_finalize;
}


static void skk_expr_node_instance_init (SkkExprNode * self) {
	self->ref_count = 1;
}


static void skk_expr_node_finalize (SkkExprNode* obj) {
	SkkExprNode * self;
	self = SKK_EXPR_NODE (obj);
	_g_object_unref0 (self->nodes);
	_g_free0 (self->data);
}


GType skk_expr_node_get_type (void) {
	static volatile gsize skk_expr_node_type_id__volatile = 0;
	if (g_once_init_enter (&skk_expr_node_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { skk_value_expr_node_init, skk_value_expr_node_free_value, skk_value_expr_node_copy_value, skk_value_expr_node_peek_pointer, "p", skk_value_expr_node_collect_value, "p", skk_value_expr_node_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (SkkExprNodeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) skk_expr_node_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SkkExprNode), 0, (GInstanceInitFunc) skk_expr_node_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType skk_expr_node_type_id;
		skk_expr_node_type_id = g_type_register_fundamental (g_type_fundamental_next (), "SkkExprNode", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&skk_expr_node_type_id__volatile, skk_expr_node_type_id);
	}
	return skk_expr_node_type_id__volatile;
}


gpointer skk_expr_node_ref (gpointer instance) {
	SkkExprNode* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void skk_expr_node_unref (gpointer instance) {
	SkkExprNode* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		SKK_EXPR_NODE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


static gboolean string_get_next_char (const gchar* self, gint* index, gunichar* c) {
	gunichar _vala_c = 0U;
	gboolean result = FALSE;
	gint _tmp0_;
	gunichar _tmp1_ = 0U;
	gunichar _tmp2_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = *index;
	_tmp1_ = g_utf8_get_char (((gchar*) self) + _tmp0_);
	_vala_c = _tmp1_;
	_tmp2_ = _vala_c;
	if (_tmp2_ != ((gunichar) 0)) {
		gint _tmp3_;
		gchar* _tmp4_ = NULL;
		_tmp3_ = *index;
		_tmp4_ = g_utf8_next_char (((gchar*) self) + _tmp3_);
		*index = (gint) (_tmp4_ - ((gchar*) self));
		result = TRUE;
		if (c) {
			*c = _vala_c;
		}
		return result;
	} else {
		result = FALSE;
		if (c) {
			*c = _vala_c;
		}
		return result;
	}
	if (c) {
		*c = _vala_c;
	}
}


SkkExprNode* skk_expr_reader_read_symbol (SkkExprReader* self, const gchar* expr, gint* index) {
	SkkExprNode* result = NULL;
	GString* _tmp0_;
	GString* builder;
	gboolean stop;
	gunichar uc;
	SkkExprNode* _tmp15_;
	SkkExprNode* node;
	GString* _tmp16_;
	const gchar* _tmp17_;
	gchar* _tmp18_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (expr != NULL, NULL);
	_tmp0_ = g_string_new ("");
	builder = _tmp0_;
	stop = FALSE;
	uc = (gunichar) '\0';
	while (TRUE) {
		gboolean _tmp1_ = FALSE;
		gboolean _tmp2_;
		gboolean _tmp6_;
		gunichar _tmp7_;
		_tmp2_ = stop;
		if (!_tmp2_) {
			const gchar* _tmp3_;
			gunichar _tmp4_ = 0U;
			gboolean _tmp5_ = FALSE;
			_tmp3_ = expr;
			_tmp5_ = string_get_next_char (_tmp3_, index, &_tmp4_);
			uc = _tmp4_;
			_tmp1_ = _tmp5_;
		} else {
			_tmp1_ = FALSE;
		}
		_tmp6_ = _tmp1_;
		if (!_tmp6_) {
			break;
		}
		_tmp7_ = uc;
		switch (_tmp7_) {
			case '\\':
			{
				const gchar* _tmp8_;
				gunichar _tmp9_ = 0U;
				gboolean _tmp10_ = FALSE;
				_tmp8_ = expr;
				_tmp10_ = string_get_next_char (_tmp8_, index, &_tmp9_);
				uc = _tmp9_;
				if (_tmp10_) {
					GString* _tmp11_;
					gunichar _tmp12_;
					_tmp11_ = builder;
					_tmp12_ = uc;
					g_string_append_unichar (_tmp11_, _tmp12_);
				}
				break;
			}
			case '(':
			case ')':
			case '"':
			case ' ':
			{
				stop = TRUE;
				break;
			}
			default:
			{
				GString* _tmp13_;
				gunichar _tmp14_;
				_tmp13_ = builder;
				_tmp14_ = uc;
				g_string_append_unichar (_tmp13_, _tmp14_);
				break;
			}
		}
	}
	_tmp15_ = skk_expr_node_new (SKK_EXPR_NODE_TYPE_SYMBOL);
	node = _tmp15_;
	_tmp16_ = builder;
	_tmp17_ = _tmp16_->str;
	_tmp18_ = g_strdup (_tmp17_);
	_g_free0 (node->data);
	node->data = _tmp18_;
	result = node;
	_g_string_free0 (builder);
	return result;
}


static gchar string_get (const gchar* self, glong index) {
	gchar result = '\0';
	glong _tmp0_;
	gchar _tmp1_;
	g_return_val_if_fail (self != NULL, '\0');
	_tmp0_ = index;
	_tmp1_ = ((gchar*) self)[_tmp0_];
	result = _tmp1_;
	return result;
}


SkkExprNode* skk_expr_reader_read_string (SkkExprReader* self, const gchar* expr, gint* index) {
	SkkExprNode* result = NULL;
	gboolean _tmp0_ = FALSE;
	gint _tmp1_;
	const gchar* _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	gboolean _tmp8_;
	GString* _tmp9_;
	GString* builder;
	gint _tmp10_;
	gboolean stop;
	gunichar uc;
	SkkExprNode* _tmp68_;
	SkkExprNode* node;
	GString* _tmp69_;
	const gchar* _tmp70_;
	gchar* _tmp71_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (expr != NULL, NULL);
	_tmp1_ = *index;
	_tmp2_ = expr;
	_tmp3_ = strlen (_tmp2_);
	_tmp4_ = _tmp3_;
	if (_tmp1_ < _tmp4_) {
		const gchar* _tmp5_;
		gint _tmp6_;
		gchar _tmp7_ = '\0';
		_tmp5_ = expr;
		_tmp6_ = *index;
		_tmp7_ = string_get (_tmp5_, (glong) _tmp6_);
		_tmp0_ = _tmp7_ == '"';
	} else {
		_tmp0_ = FALSE;
	}
	_tmp8_ = _tmp0_;
	g_return_val_if_fail (_tmp8_, NULL);
	_tmp9_ = g_string_new ("");
	builder = _tmp9_;
	_tmp10_ = *index;
	*index = _tmp10_ + 1;
	stop = FALSE;
	uc = (gunichar) '\0';
	while (TRUE) {
		gboolean _tmp11_ = FALSE;
		gboolean _tmp12_;
		gboolean _tmp16_;
		gunichar _tmp17_;
		_tmp12_ = stop;
		if (!_tmp12_) {
			const gchar* _tmp13_;
			gunichar _tmp14_ = 0U;
			gboolean _tmp15_ = FALSE;
			_tmp13_ = expr;
			_tmp15_ = string_get_next_char (_tmp13_, index, &_tmp14_);
			uc = _tmp14_;
			_tmp11_ = _tmp15_;
		} else {
			_tmp11_ = FALSE;
		}
		_tmp16_ = _tmp11_;
		if (!_tmp16_) {
			break;
		}
		_tmp17_ = uc;
		switch (_tmp17_) {
			case '\\':
			{
				const gchar* _tmp18_;
				gunichar _tmp19_ = 0U;
				gboolean _tmp20_ = FALSE;
				_tmp18_ = expr;
				_tmp20_ = string_get_next_char (_tmp18_, index, &_tmp19_);
				uc = _tmp19_;
				if (_tmp20_) {
					gunichar _tmp21_;
					GString* _tmp64_;
					gunichar _tmp65_;
					_tmp21_ = uc;
					switch (_tmp21_) {
						case '0':
						{
							gint num;
							gint _tmp32_;
							gint _tmp33_;
							num = 0;
							while (TRUE) {
								const gchar* _tmp22_;
								gunichar _tmp23_ = 0U;
								gboolean _tmp24_ = FALSE;
								gboolean _tmp25_ = FALSE;
								gunichar _tmp26_;
								gboolean _tmp28_;
								gint _tmp29_;
								gint _tmp30_;
								gunichar _tmp31_;
								_tmp22_ = expr;
								_tmp24_ = string_get_next_char (_tmp22_, index, &_tmp23_);
								uc = _tmp23_;
								if (!_tmp24_) {
									break;
								}
								_tmp26_ = uc;
								if (_tmp26_ < ((gunichar) '0')) {
									_tmp25_ = TRUE;
								} else {
									gunichar _tmp27_;
									_tmp27_ = uc;
									_tmp25_ = _tmp27_ > ((gunichar) '7');
								}
								_tmp28_ = _tmp25_;
								if (_tmp28_) {
									break;
								}
								_tmp29_ = num;
								num = _tmp29_ << 3;
								_tmp30_ = num;
								_tmp31_ = uc;
								num = _tmp30_ + (((gint) _tmp31_) - '0');
							}
							_tmp32_ = *index;
							*index = _tmp32_ - 1;
							_tmp33_ = num;
							uc = (gunichar) _tmp33_;
							break;
						}
						case 'x':
						{
							gint num;
							gint _tmp62_;
							gint _tmp63_;
							num = 0;
							while (TRUE) {
								const gchar* _tmp34_;
								gunichar _tmp35_ = 0U;
								gboolean _tmp36_ = FALSE;
								gunichar _tmp37_;
								gunichar _tmp38_ = 0U;
								gboolean _tmp39_ = FALSE;
								gboolean _tmp40_ = FALSE;
								gunichar _tmp41_;
								gboolean _tmp43_;
								gboolean _tmp48_;
								_tmp34_ = expr;
								_tmp36_ = string_get_next_char (_tmp34_, index, &_tmp35_);
								uc = _tmp35_;
								if (!_tmp36_) {
									break;
								}
								_tmp37_ = uc;
								_tmp38_ = g_unichar_tolower (_tmp37_);
								uc = _tmp38_;
								_tmp41_ = uc;
								if (((gunichar) '0') <= _tmp41_) {
									gunichar _tmp42_;
									_tmp42_ = uc;
									_tmp40_ = _tmp42_ <= ((gunichar) '9');
								} else {
									_tmp40_ = FALSE;
								}
								_tmp43_ = _tmp40_;
								if (_tmp43_) {
									_tmp39_ = TRUE;
								} else {
									gboolean _tmp44_ = FALSE;
									gunichar _tmp45_;
									gboolean _tmp47_;
									_tmp45_ = uc;
									if (((gunichar) 'a') <= _tmp45_) {
										gunichar _tmp46_;
										_tmp46_ = uc;
										_tmp44_ = _tmp46_ <= ((gunichar) 'f');
									} else {
										_tmp44_ = FALSE;
									}
									_tmp47_ = _tmp44_;
									_tmp39_ = _tmp47_;
								}
								_tmp48_ = _tmp39_;
								if (_tmp48_) {
									gint _tmp49_;
									gboolean _tmp50_ = FALSE;
									gunichar _tmp51_;
									gboolean _tmp53_;
									_tmp49_ = num;
									num = _tmp49_ << 4;
									_tmp51_ = uc;
									if (((gunichar) '0') <= _tmp51_) {
										gunichar _tmp52_;
										_tmp52_ = uc;
										_tmp50_ = _tmp52_ <= ((gunichar) '9');
									} else {
										_tmp50_ = FALSE;
									}
									_tmp53_ = _tmp50_;
									if (_tmp53_) {
										gint _tmp54_;
										gunichar _tmp55_;
										_tmp54_ = num;
										_tmp55_ = uc;
										num = _tmp54_ + (((gint) _tmp55_) - '0');
									} else {
										gboolean _tmp56_ = FALSE;
										gunichar _tmp57_;
										gboolean _tmp59_;
										_tmp57_ = uc;
										if (((gunichar) 'a') <= _tmp57_) {
											gunichar _tmp58_;
											_tmp58_ = uc;
											_tmp56_ = _tmp58_ <= ((gunichar) 'f');
										} else {
											_tmp56_ = FALSE;
										}
										_tmp59_ = _tmp56_;
										if (_tmp59_) {
											gint _tmp60_;
											gunichar _tmp61_;
											_tmp60_ = num;
											_tmp61_ = uc;
											num = _tmp60_ + ((((gint) _tmp61_) - 'a') + 10);
										}
									}
								} else {
									break;
								}
							}
							_tmp62_ = *index;
							*index = _tmp62_ - 1;
							_tmp63_ = num;
							uc = (gunichar) _tmp63_;
							break;
						}
						default:
						{
							break;
						}
					}
					_tmp64_ = builder;
					_tmp65_ = uc;
					g_string_append_unichar (_tmp64_, _tmp65_);
				}
				break;
			}
			case '\"':
			{
				stop = TRUE;
				break;
			}
			default:
			{
				GString* _tmp66_;
				gunichar _tmp67_;
				_tmp66_ = builder;
				_tmp67_ = uc;
				g_string_append_unichar (_tmp66_, _tmp67_);
				break;
			}
		}
	}
	_tmp68_ = skk_expr_node_new (SKK_EXPR_NODE_TYPE_STRING);
	node = _tmp68_;
	_tmp69_ = builder;
	_tmp70_ = _tmp69_->str;
	_tmp71_ = g_strdup (_tmp70_);
	_g_free0 (node->data);
	node->data = _tmp71_;
	result = node;
	_g_string_free0 (builder);
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


SkkExprNode* skk_expr_reader_read_expr (SkkExprReader* self, const gchar* expr, gint* index) {
	SkkExprNode* result = NULL;
	gboolean _tmp0_ = FALSE;
	gint _tmp1_;
	const gchar* _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	gboolean _tmp8_;
	GeeLinkedList* _tmp9_;
	GeeLinkedList* nodes;
	gboolean stop;
	gint _tmp10_;
	gunichar uc;
	SkkExprNode* _tmp34_;
	SkkExprNode* node;
	GeeLinkedList* _tmp35_;
	GeeLinkedList* _tmp36_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (expr != NULL, NULL);
	_tmp1_ = *index;
	_tmp2_ = expr;
	_tmp3_ = strlen (_tmp2_);
	_tmp4_ = _tmp3_;
	if (_tmp1_ < _tmp4_) {
		const gchar* _tmp5_;
		gint _tmp6_;
		gchar _tmp7_ = '\0';
		_tmp5_ = expr;
		_tmp6_ = *index;
		_tmp7_ = string_get (_tmp5_, (glong) _tmp6_);
		_tmp0_ = _tmp7_ == '(';
	} else {
		_tmp0_ = FALSE;
	}
	_tmp8_ = _tmp0_;
	g_return_val_if_fail (_tmp8_, NULL);
	_tmp9_ = gee_linked_list_new (SKK_TYPE_EXPR_NODE, (GBoxedCopyFunc) skk_expr_node_ref, skk_expr_node_unref, NULL);
	nodes = _tmp9_;
	stop = FALSE;
	_tmp10_ = *index;
	*index = _tmp10_ + 1;
	uc = (gunichar) '\0';
	while (TRUE) {
		gboolean _tmp11_ = FALSE;
		gboolean _tmp12_;
		gboolean _tmp16_;
		gunichar _tmp17_;
		_tmp12_ = stop;
		if (!_tmp12_) {
			const gchar* _tmp13_;
			gunichar _tmp14_ = 0U;
			gboolean _tmp15_ = FALSE;
			_tmp13_ = expr;
			_tmp15_ = string_get_next_char (_tmp13_, index, &_tmp14_);
			uc = _tmp14_;
			_tmp11_ = _tmp15_;
		} else {
			_tmp11_ = FALSE;
		}
		_tmp16_ = _tmp11_;
		if (!_tmp16_) {
			break;
		}
		_tmp17_ = uc;
		switch (_tmp17_) {
			case ' ':
			{
				break;
			}
			case ')':
			{
				gint _tmp18_;
				_tmp18_ = *index;
				*index = _tmp18_ + 1;
				stop = TRUE;
				break;
			}
			case '(':
			{
				gint _tmp19_;
				GeeLinkedList* _tmp20_;
				const gchar* _tmp21_;
				SkkExprNode* _tmp22_ = NULL;
				SkkExprNode* _tmp23_;
				_tmp19_ = *index;
				*index = _tmp19_ - 1;
				_tmp20_ = nodes;
				_tmp21_ = expr;
				_tmp22_ = skk_expr_reader_read_expr (self, _tmp21_, index);
				_tmp23_ = _tmp22_;
				gee_abstract_collection_add ((GeeAbstractCollection*) _tmp20_, _tmp23_);
				_skk_expr_node_unref0 (_tmp23_);
				break;
			}
			case '"':
			{
				gint _tmp24_;
				GeeLinkedList* _tmp25_;
				const gchar* _tmp26_;
				SkkExprNode* _tmp27_ = NULL;
				SkkExprNode* _tmp28_;
				_tmp24_ = *index;
				*index = _tmp24_ - 1;
				_tmp25_ = nodes;
				_tmp26_ = expr;
				_tmp27_ = skk_expr_reader_read_string (self, _tmp26_, index);
				_tmp28_ = _tmp27_;
				gee_abstract_collection_add ((GeeAbstractCollection*) _tmp25_, _tmp28_);
				_skk_expr_node_unref0 (_tmp28_);
				break;
			}
			default:
			{
				gint _tmp29_;
				GeeLinkedList* _tmp30_;
				const gchar* _tmp31_;
				SkkExprNode* _tmp32_ = NULL;
				SkkExprNode* _tmp33_;
				_tmp29_ = *index;
				*index = _tmp29_ - 1;
				_tmp30_ = nodes;
				_tmp31_ = expr;
				_tmp32_ = skk_expr_reader_read_symbol (self, _tmp31_, index);
				_tmp33_ = _tmp32_;
				gee_abstract_collection_add ((GeeAbstractCollection*) _tmp30_, _tmp33_);
				_skk_expr_node_unref0 (_tmp33_);
				break;
			}
		}
	}
	_tmp34_ = skk_expr_node_new (SKK_EXPR_NODE_TYPE_ARRAY);
	node = _tmp34_;
	_tmp35_ = nodes;
	_tmp36_ = _g_object_ref0 (_tmp35_);
	_g_object_unref0 (node->nodes);
	node->nodes = _tmp36_;
	result = node;
	_g_object_unref0 (nodes);
	return result;
}


SkkExprReader* skk_expr_reader_construct (GType object_type) {
	SkkExprReader * self = NULL;
	self = (SkkExprReader*) g_object_new (object_type, NULL);
	return self;
}


SkkExprReader* skk_expr_reader_new (void) {
	return skk_expr_reader_construct (SKK_TYPE_EXPR_READER);
}


static void skk_expr_reader_class_init (SkkExprReaderClass * klass) {
	skk_expr_reader_parent_class = g_type_class_peek_parent (klass);
}


static void skk_expr_reader_instance_init (SkkExprReader * self) {
}


GType skk_expr_reader_get_type (void) {
	static volatile gsize skk_expr_reader_type_id__volatile = 0;
	if (g_once_init_enter (&skk_expr_reader_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SkkExprReaderClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) skk_expr_reader_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SkkExprReader), 0, (GInstanceInitFunc) skk_expr_reader_instance_init, NULL };
		GType skk_expr_reader_type_id;
		skk_expr_reader_type_id = g_type_register_static (G_TYPE_OBJECT, "SkkExprReader", &g_define_type_info, 0);
		g_once_init_leave (&skk_expr_reader_type_id__volatile, skk_expr_reader_type_id);
	}
	return skk_expr_reader_type_id__volatile;
}


gchar* skk_expr_evaluator_eval (SkkExprEvaluator* self, SkkExprNode* node) {
	gchar* result = NULL;
	SkkExprNode* _tmp0_;
	SkkExprNodeType _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (node != NULL, NULL);
	_tmp0_ = node;
	_tmp1_ = _tmp0_->type;
	if (_tmp1_ == SKK_EXPR_NODE_TYPE_ARRAY) {
		SkkExprNode* _tmp2_;
		GeeLinkedList* _tmp3_;
		GeeListIterator* _tmp4_ = NULL;
		GeeListIterator* iter;
		GeeListIterator* _tmp5_;
		gboolean _tmp6_ = FALSE;
		_tmp2_ = node;
		_tmp3_ = _tmp2_->nodes;
		_tmp4_ = gee_abstract_list_list_iterator ((GeeAbstractList*) _tmp3_);
		iter = _tmp4_;
		_tmp5_ = iter;
		_tmp6_ = gee_iterator_first ((GeeIterator*) _tmp5_);
		if (_tmp6_) {
			GeeListIterator* _tmp7_;
			gpointer _tmp8_ = NULL;
			SkkExprNode* funcall;
			SkkExprNode* _tmp9_;
			SkkExprNodeType _tmp10_;
			_tmp7_ = iter;
			_tmp8_ = gee_iterator_get ((GeeIterator*) _tmp7_);
			funcall = (SkkExprNode*) _tmp8_;
			_tmp9_ = funcall;
			_tmp10_ = _tmp9_->type;
			if (_tmp10_ == SKK_EXPR_NODE_TYPE_SYMBOL) {
				SkkExprNode* _tmp11_;
				const gchar* _tmp12_;
				_tmp11_ = funcall;
				_tmp12_ = _tmp11_->data;
				if (g_strcmp0 (_tmp12_, "concat") == 0) {
					GString* _tmp13_;
					GString* builder;
					GString* _tmp23_;
					const gchar* _tmp24_;
					gchar* _tmp25_;
					_tmp13_ = g_string_new ("");
					builder = _tmp13_;
					while (TRUE) {
						GeeListIterator* _tmp14_;
						gboolean _tmp15_ = FALSE;
						GeeListIterator* _tmp16_;
						gpointer _tmp17_ = NULL;
						SkkExprNode* arg;
						SkkExprNode* _tmp18_;
						SkkExprNodeType _tmp19_;
						_tmp14_ = iter;
						_tmp15_ = gee_iterator_next ((GeeIterator*) _tmp14_);
						if (!_tmp15_) {
							break;
						}
						_tmp16_ = iter;
						_tmp17_ = gee_iterator_get ((GeeIterator*) _tmp16_);
						arg = (SkkExprNode*) _tmp17_;
						_tmp18_ = arg;
						_tmp19_ = _tmp18_->type;
						if (_tmp19_ == SKK_EXPR_NODE_TYPE_STRING) {
							GString* _tmp20_;
							SkkExprNode* _tmp21_;
							const gchar* _tmp22_;
							_tmp20_ = builder;
							_tmp21_ = arg;
							_tmp22_ = _tmp21_->data;
							g_string_append (_tmp20_, _tmp22_);
						}
						_skk_expr_node_unref0 (arg);
					}
					_tmp23_ = builder;
					_tmp24_ = _tmp23_->str;
					_tmp25_ = g_strdup (_tmp24_);
					result = _tmp25_;
					_g_string_free0 (builder);
					_skk_expr_node_unref0 (funcall);
					_g_object_unref0 (iter);
					return result;
				} else {
					SkkExprNode* _tmp26_;
					const gchar* _tmp27_;
					_tmp26_ = funcall;
					_tmp27_ = _tmp26_->data;
					if (g_strcmp0 (_tmp27_, "current-time-string") == 0) {
						GDateTime* _tmp28_;
						GDateTime* datetime;
						GDateTime* _tmp29_;
						gchar* _tmp30_ = NULL;
						_tmp28_ = g_date_time_new_now_local ();
						datetime = _tmp28_;
						_tmp29_ = datetime;
						_tmp30_ = g_date_time_format (_tmp29_, "%a, %d %b %Y %T %z");
						result = _tmp30_;
						_g_date_time_unref0 (datetime);
						_skk_expr_node_unref0 (funcall);
						_g_object_unref0 (iter);
						return result;
					} else {
						SkkExprNode* _tmp31_;
						const gchar* _tmp32_;
						_tmp31_ = funcall;
						_tmp32_ = _tmp31_->data;
						if (g_strcmp0 (_tmp32_, "pwd") == 0) {
							gchar* _tmp33_ = NULL;
							_tmp33_ = g_get_current_dir ();
							result = _tmp33_;
							_skk_expr_node_unref0 (funcall);
							_g_object_unref0 (iter);
							return result;
						} else {
							SkkExprNode* _tmp34_;
							const gchar* _tmp35_;
							_tmp34_ = funcall;
							_tmp35_ = _tmp34_->data;
							if (g_strcmp0 (_tmp35_, "skk-version") == 0) {
								gchar* _tmp36_ = NULL;
								_tmp36_ = g_strdup_printf ("%s/%s", PACKAGE_NAME, PACKAGE_VERSION);
								result = _tmp36_;
								_skk_expr_node_unref0 (funcall);
								_g_object_unref0 (iter);
								return result;
							}
						}
					}
				}
			}
			_skk_expr_node_unref0 (funcall);
		}
		_g_object_unref0 (iter);
	}
	result = NULL;
	return result;
}


SkkExprEvaluator* skk_expr_evaluator_construct (GType object_type) {
	SkkExprEvaluator * self = NULL;
	self = (SkkExprEvaluator*) g_object_new (object_type, NULL);
	return self;
}


SkkExprEvaluator* skk_expr_evaluator_new (void) {
	return skk_expr_evaluator_construct (SKK_TYPE_EXPR_EVALUATOR);
}


static void skk_expr_evaluator_class_init (SkkExprEvaluatorClass * klass) {
	skk_expr_evaluator_parent_class = g_type_class_peek_parent (klass);
}


static void skk_expr_evaluator_instance_init (SkkExprEvaluator * self) {
}


GType skk_expr_evaluator_get_type (void) {
	static volatile gsize skk_expr_evaluator_type_id__volatile = 0;
	if (g_once_init_enter (&skk_expr_evaluator_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SkkExprEvaluatorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) skk_expr_evaluator_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SkkExprEvaluator), 0, (GInstanceInitFunc) skk_expr_evaluator_instance_init, NULL };
		GType skk_expr_evaluator_type_id;
		skk_expr_evaluator_type_id = g_type_register_static (G_TYPE_OBJECT, "SkkExprEvaluator", &g_define_type_info, 0);
		g_once_init_leave (&skk_expr_evaluator_type_id__volatile, skk_expr_evaluator_type_id);
	}
	return skk_expr_evaluator_type_id__volatile;
}


