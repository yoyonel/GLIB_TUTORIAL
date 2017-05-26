#include <test-object.h>

#include "test-object-private.h"

/**
 * @brief main
 */
int main (void)
{
    TestObject *obj = NULL;

    obj = g_object_new (TEST_TYPE_OBJECT, NULL);

    // Champs public
    obj->i = 21;
    g_print("obj(=%ld)->i(=%ld) = %d\n",
            obj, &(obj->i), obj->i);
    obj->k = 42;
    g_print("obj(=%ld)->k(=%ld) = %d\n",
            obj, &(obj->k), obj->k);

    // Champs privés
    TestObjectPrivate *priv = NULL;
    priv = obj->_priv;
    priv->j = 42;
    g_print("obj(=%ld)->_priv->j(=%ld) = %d\n",
            obj, &(obj->_priv->j), obj->_priv->j);

    g_object_unref (obj);

    return 0;
}
