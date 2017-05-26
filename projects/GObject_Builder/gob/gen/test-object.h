/* Generated by GOB (v2.0.20)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>
#ifndef H_TEST_OBJECT
#define H_TEST_OBJECT

G_BEGIN_DECLS


/*
 * Type checking and casting macros
 */
#define TEST_TYPE_OBJECT	(test_object_get_type())
#define TEST_OBJECT(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), test_object_get_type(), TestObject)
#define TEST_OBJECT_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), test_object_get_type(), TestObject const)
#define TEST_OBJECT_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), test_object_get_type(), TestObjectClass)
#define TEST_IS_OBJECT(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), test_object_get_type ())

#define TEST_OBJECT_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), test_object_get_type(), TestObjectClass)

/* Private structure type */
typedef struct _TestObjectPrivate TestObjectPrivate;

/*
 * Main object structure
 */
#ifndef __TYPEDEF_TEST_OBJECT__
#define __TYPEDEF_TEST_OBJECT__
typedef struct _TestObject TestObject;
#endif
struct _TestObject {
	GObject __parent__;
	/*< public >*/
	int i;
	/*< private >*/
	int k; /* protected */
	TestObjectPrivate *_priv;
};

/*
 * Class definition
 */
typedef struct _TestObjectClass TestObjectClass;
struct _TestObjectClass {
	GObjectClass __parent__;
};


/*
 * Public methods
 */
GType	test_object_get_type	(void) G_GNUC_CONST;

G_END_DECLS

#endif /* not H_TEST_OBJECT */
