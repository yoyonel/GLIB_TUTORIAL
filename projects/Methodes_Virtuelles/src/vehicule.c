#include "vehicule.h"

#define VEHICULE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), \
    TYPE_VEHICULE,                    \
    VehiculePrivate))

static void vehicule_reset_flags (Vehicule *self);
static GObject *vehicule_constructor (GType type, guint n_construct_properties,
                                      GObjectConstructParam *construct_properties);
static void vehicule_finalize (GObject *);

static GObjectClass *parent_class = NULL;

static void vehicule_rouler (Vehicule *self, gint distance);

G_DEFINE_TYPE (Vehicule, vehicule, G_TYPE_OBJECT)

// #############################################################################

static void vehicule_class_init (VehiculeClass *klass)
{
    g_return_if_fail (klass != NULL);

    klass->avancer = vehicule_rouler;

    g_type_class_add_private (klass, sizeof (VehiculePrivate));

    GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

    gobject_class->constructor = vehicule_constructor;
    gobject_class->finalize = vehicule_finalize;

    parent_class = g_type_class_peek_parent (gobject_class);
    //    (void)class_data;
}

static GObject *vehicule_constructor (GType type, guint n_construct_properties,
                                      GObjectConstructParam *construct_properties)
{
    GObject *obj = NULL;

    obj = parent_class->constructor (type,
                                     n_construct_properties,
                                     construct_properties);

    VehiculePrivate *priv = VEHICULE_GET_PRIVATE (obj);
    priv->vitesse = 24;

    return obj;
}

static void vehicule_finalize (GObject *self)
{
}

// #############################################################################

// #############################################################################

static void vehicule_init (Vehicule *self)
{
    g_return_if_fail (self != NULL);
}

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

void vehicule_avancer (Vehicule *self, gint distance)
{
    // url: https://developer.gnome.org/gobject/stable/howto-gobject-methods.html
    VehiculeClass *klass;
    g_return_if_fail (VEHICULE_GET_CLASS (self));
    klass = VEHICULE_GET_CLASS (self);
    g_return_if_fail (klass->avancer != NULL);
    klass->avancer (self, distance);
}

void vehicule_avancer_2 (Vehicule *self, gint distance)
{
    // url: https://www.developpez.net/forums/d656612/general-developpement/programmation-systeme/linux/gtk/contribuez/programmation-orientee-objet-c-goject-classes/#post7537791
    VEHICULE_GET_CLASS (self)->avancer (self, distance);
}

static void vehicule_rouler (Vehicule *self, gint distance)
{
    g_print ("[virtual=vehicule_rouler](self=%ld)->avance(%d)\n", self, distance);
}

// #############################################################################
