#include "vehicule.h"

// Pour y accéder à partir d'une instance de notre classe, nous créons une macro : 
#define VEHICULE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), \
    TYPE_VEHICULE,                    \
    VehiculePrivate))

static void vehicule_reset_flags (Vehicule *self);
// Constructor
static GObject *vehicule_constructor (GType type, guint n_construct_properties,
                                      GObjectConstructParam *construct_properties);
static void vehicule_finalize (GObject *);

/* pointer to the class of our parent */
static GObjectClass *parent_class = NULL;

G_DEFINE_TYPE (Vehicule, vehicule, G_TYPE_OBJECT)

// #############################################################################

// url: http://maemo.org/api_refs/4.0/gobject/howto-gobject.html
static void vehicule_class_init (VehiculeClass *klass)
{
    g_print ("[vehicule_class_init]\n");

    g_return_if_fail (klass != NULL);

    // nous demandons à GObject, d'enregistrer cette structure lors de l'initialisation de notre classe :
    g_type_class_add_private (klass, sizeof (VehiculePrivate));

    GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

    // Le constructeur et le destructeur sont automatiquement appelés par GObject lorsque cela est nécessaire.
    // Comme nous ne devons pas les appeler directement, il faut les enregistrer lors de l'initialisation de notre classe :
    gobject_class->constructor = vehicule_constructor;
    gobject_class->finalize = vehicule_finalize;

    parent_class = g_type_class_peek_parent (gobject_class);
//    (void)class_data;
}

static GObject *vehicule_constructor (GType type, guint n_construct_properties,
                                      GObjectConstructParam *construct_properties)
{
    g_print ("[vehicule_constructor]\n");
    GObject *obj = NULL;

    /* Appel du constructeur de la classe parent */
    // Et dans le constructeur, nous devons commencer par appeler le construteur de la classe parent :
    obj = parent_class->constructor (type,
                                     n_construct_properties,
                                     construct_properties);

    // Access to private data
    VehiculePrivate *priv = VEHICULE_GET_PRIVATE (obj);
    priv->vitesse = 24;

    return obj;
}

static void vehicule_finalize (GObject *self)
{
    g_print ("[vehicule_finalize]\n");
}

// #############################################################################

// #############################################################################

static void vehicule_init (Vehicule *self)
{
    g_return_if_fail (self != NULL);
}

// url: https://stackoverflow.com/questions/35425790/how-to-call-the-static-function-from-another-c-file
// For restricting function access from other file, the keyword static is used 
// Access to static functions is restricted to the file except where they are declared.
// When we want to restrict access to functions from outer world, we have to make them static. 
// If you want access functions from other file, then go for global function i.e non static functions.

// Nous pouvons aussi définir des méthodes privées à notre classe, 
// simplement en les définissant dans le fichier source en tant que fonctions statiques :
/*< private >*/
static void vehicule_reset_flags (Vehicule *self)
{
    g_return_if_fail (self != NULL);
    g_return_if_fail (IS_VEHICULE (self));

    self->flags = 0;
}

void vehicule_show_vitesse (Vehicule *self)
{
    VehiculePrivate *priv = NULL;

    priv = VEHICULE_GET_PRIVATE (self);
    g_print ("[private] priv->vitesse: %d\n", priv->vitesse);
}

// #############################################################################
