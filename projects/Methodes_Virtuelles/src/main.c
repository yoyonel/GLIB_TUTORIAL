#include "vehicule.h"

int main (void)
{
    Vehicule *v = NULL;

    v = g_object_new (TYPE_VEHICULE, NULL);

    vehicule_avancer (v, 4);

    g_object_unref (v);

    return 0;
}
