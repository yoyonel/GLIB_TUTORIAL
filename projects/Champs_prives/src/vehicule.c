#include "vehicule.h"

// Pour y accéder à partir d'une instance de notre classe, nous créons une macro : 
#define VEHICULE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), \
                                 TYPE_VEHICULE,                    \
                                 VehiculePrivate))

static void vehicule_reset_flags (Vehicule *self);

G_DEFINE_TYPE (Vehicule, vehicule, G_TYPE_OBJECT)

// #############################################################################

// url: http://maemo.org/api_refs/4.0/gobject/howto-gobject.html
static void vehicule_class_init (VehiculeClass *klass)
{
  g_return_if_fail (klass != NULL);

  // nous demandons à GObject, d'enregistrer cette structure lors de l'initialisation de notre classe :
  g_type_class_add_private (klass, sizeof (VehiculePrivate));
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
