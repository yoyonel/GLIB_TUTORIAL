#include "vehicule.h"

#define VEHICULE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), \
    TYPE_VEHICULE,                    \
    VehiculePrivate))

static void vehicule_reset_flags (Vehicule *self);
static GObject *vehicule_constructor (GType type, guint n_construct_properties,
                                      GObjectConstructParam *construct_properties);
static void vehicule_finalize (GObject *);

static GObjectClass *parent_class = NULL;

G_DEFINE_TYPE (Vehicule, vehicule, G_TYPE_OBJECT)

// #############################################################################

static void vehicule_class_init (VehiculeClass *klass)
{
    g_print ("[vehicule_class_init]\n");

    g_return_if_fail (klass != NULL);

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
    g_print ("[vehicule_constructor]\n");
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
    g_print ("[vehicule_finalize]\n");
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

// #############################################################################
