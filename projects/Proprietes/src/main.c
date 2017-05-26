#include "vehicule.h"

/**
 * @brief gbool_to_char
 * @param val
 * @return
 */
const char* gbool_to_char (GValue *val)
{
    return g_value_get_boolean (val) ? "True": "False";
}

/**
 * @brief print_property
 * @param v
 */
void print_property (GObject *v)
{
    GValue val = {0};
    g_value_init (&val, G_TYPE_BOOLEAN);
    g_object_get_property(G_OBJECT (v), "window-open", &val);
    // url: https://developer.gnome.org/gobject/stable/gobject-Standard-Parameter-and-Value-Types.html#g-value-get-boolean
    g_print ("(GObject *v=%ld).property('window-open'): %s\n",
             v, gbool_to_char(&val));
}

/**
 * @brief test_property_0
 * @return
 */
GObject *test_property_0 ()
{
    GObject *vehicule = NULL;
    GValue val = {0};

    vehicule = g_object_new (TYPE_VEHICULE, NULL);
    g_value_init (&val, G_TYPE_BOOLEAN);
    g_value_set_boolean (&val, FALSE);
    g_object_set_property (G_OBJECT (vehicule), "window-open", &val);

    g_print ("g_object_set_property (G_OBJECT (vehicule=%ld), \"window-open\", &val=%s);\n",
             vehicule, gbool_to_char (&val) );

    return vehicule;
}

/**
 * @brief test_property_1
 * @return
 */
GObject *test_property_1 ()
{
    GObject *vehicule = NULL;
    vehicule = g_object_new (TYPE_VEHICULE, NULL);
    // Soit par lot en passant directement la valeur :
    // url: https://developer.gnome.org/gobject/stable/gobject-The-Base-Object-Type.html#g-object-set
    g_object_set (vehicule, "window-open", TRUE, NULL);

    g_print ("g_object_set (%ld, \"window-open\", TRUE, NULL);\n", vehicule);

    return vehicule;
}

/**
 * @brief test_property_2
 * @return
 */
GObject *test_property_2 ()
{
    GObject *vehicule = NULL;
    // Syntaxe qui peut aussi être utilisée lors de la construction de l'objet si la propriété le permet :
    vehicule = g_object_new (TYPE_VEHICULE, "window-open", FALSE, NULL);
    g_print ("vehicule(=%ld) = g_object_new (TYPE_VEHICULE, \"window-open\", FALSE, NULL);\n",
             vehicule);
    return vehicule;
}

/**
 * @brief main
 */
int main (void)
{
    GObject *v = NULL;

    // les propriétés, voici comment les modifier
    v = test_property_0 ();
    print_property (v);
    g_object_unref (v);

    v = test_property_1 ();
    print_property (v);
    g_object_unref (v);

    v = test_property_2 ();
    print_property (v);
    g_object_unref (v);

    return 0;
}
