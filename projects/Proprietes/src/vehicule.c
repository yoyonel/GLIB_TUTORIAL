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

static void vehicule_properties_init (GObjectClass *gobject_class);
static void vehicule_set_property (GObject *object, guint property_id,
                                   const GValue *value, GParamSpec *pspec);
static void vehicule_get_property (GObject *object, guint property_id,
                                   GValue *value, GParamSpec *pspec);

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

    vehicule_properties_init (gobject_class);
}

static void vehicule_properties_init (GObjectClass *gobject_class)
{
    GParamSpec *pspec = NULL;

    // une propriété de type boolean que nous définissons dans la fonction d'initialisation de notre classe :
    pspec = g_param_spec_boolean ("window-open",
                                  "Window open prop",
                                  "Set window opening",
                                  FALSE,
                                  G_PARAM_CONSTRUCT | G_PARAM_READWRITE);
    // Nous définissons donc le nom de notre propriété,
    // sa valeur par défaut ainsi que différentes options (voir GParamFlags pour plus d'informations).

    // Pour en finir avec notre initialisation, nous devons spécifier deux fonctions qui serviront d'assesseurs :
    gobject_class->set_property = vehicule_set_property;
    gobject_class->get_property = vehicule_get_property;

    // nous installons notre propriété:
    g_object_class_install_property (gobject_class,
                                     PROP_WINDOW_OPEN,
                                     pspec);
}

// Ces deux fonctions vont recevoir toutes les demandes d'accès ou de modifications de propriétés.
// Afin de traiter correctement chacune d'entre elles, nous effectuons un switch/case sur l'identifiant de la propriété :
static void vehicule_set_property (GObject *object, guint property_id,
                                   const GValue *value, GParamSpec *pspec)
{
    Vehicule *self = VEHICULE (object);
    VehiculePrivate *priv = NULL;

    priv = VEHICULE_GET_PRIVATE (self);
    switch (property_id)
    {
    case PROP_WINDOW_OPEN:
        priv->open_window = g_value_get_boolean (value);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
        break;
    }
}

static void vehicule_get_property (GObject *object, guint property_id,
                                   GValue *value, GParamSpec *pspec)
{
    Vehicule *self = VEHICULE (object);
    VehiculePrivate *priv = NULL;

    priv = VEHICULE_GET_PRIVATE (self);
    switch (property_id)
    {
    case PROP_WINDOW_OPEN:
        g_value_set_boolean (value, priv->open_window);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
        break;
    }
}
// Afin de simplifier le code de notre exemple, les assesseurs sont de simples interfaces pour notre variable privée,
// cependant rien ne nous empêche de faire appel à d'autres fonctions (par exemple personne_bouge_bras,
// afin d'éviter tous problèmes lors de la fermeture des fenêtres...).

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
    VehiculeClass *klass;
    g_return_if_fail (VEHICULE_GET_CLASS (self));
    klass = VEHICULE_GET_CLASS (self);
    g_return_if_fail (klass->avancer != NULL);
    klass->avancer (self, distance);
}

static void vehicule_rouler (Vehicule *self, gint distance)
{
    g_print ("[virtual=vehicule_rouler](self=%ld)->avance(%d)\n", self, distance);
}

// #############################################################################
