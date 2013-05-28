/* ItemFactory.c generated by valac 0.20.1, the Vala compiler
 * generated from ItemFactory.vala, do not modify */

/**/
/*  Copyright (C) 2011 Robert Dyer*/
/**/
/*  This program is free software: you can redistribute it and/or modify*/
/*  it under the terms of the GNU General Public License as published by*/
/*  the Free Software Foundation, either version 3 of the License, or*/
/*  (at your option) any later version.*/
/**/
/*  This program is distributed in the hope that it will be useful,*/
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of*/
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the*/
/*  GNU General Public License for more details.*/
/**/
/*  You should have received a copy of the GNU General Public License*/
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
/**/

#include <glib.h>
#include <glib-object.h>


#define SHELFPANEL_FACTORIES_TYPE_ITEM_FACTORY (shelfpanel_factories_item_factory_get_type ())
#define SHELFPANEL_FACTORIES_ITEM_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SHELFPANEL_FACTORIES_TYPE_ITEM_FACTORY, ShelfpanelFactoriesItemFactory))
#define SHELFPANEL_FACTORIES_ITEM_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SHELFPANEL_FACTORIES_TYPE_ITEM_FACTORY, ShelfpanelFactoriesItemFactoryClass))
#define SHELFPANEL_FACTORIES_IS_ITEM_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SHELFPANEL_FACTORIES_TYPE_ITEM_FACTORY))
#define SHELFPANEL_FACTORIES_IS_ITEM_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SHELFPANEL_FACTORIES_TYPE_ITEM_FACTORY))
#define SHELFPANEL_FACTORIES_ITEM_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SHELFPANEL_FACTORIES_TYPE_ITEM_FACTORY, ShelfpanelFactoriesItemFactoryClass))

typedef struct _ShelfpanelFactoriesItemFactory ShelfpanelFactoriesItemFactory;
typedef struct _ShelfpanelFactoriesItemFactoryClass ShelfpanelFactoriesItemFactoryClass;
typedef struct _ShelfpanelFactoriesItemFactoryPrivate ShelfpanelFactoriesItemFactoryPrivate;

struct _ShelfpanelFactoriesItemFactory {
	GObject parent_instance;
	ShelfpanelFactoriesItemFactoryPrivate * priv;
};

struct _ShelfpanelFactoriesItemFactoryClass {
	GObjectClass parent_class;
};


static gpointer shelfpanel_factories_item_factory_parent_class = NULL;

GType shelfpanel_factories_item_factory_get_type (void) G_GNUC_CONST;
enum  {
	SHELFPANEL_FACTORIES_ITEM_FACTORY_DUMMY_PROPERTY
};
ShelfpanelFactoriesItemFactory* shelfpanel_factories_item_factory_new (void);
ShelfpanelFactoriesItemFactory* shelfpanel_factories_item_factory_construct (GType object_type);


ShelfpanelFactoriesItemFactory* shelfpanel_factories_item_factory_construct (GType object_type) {
	ShelfpanelFactoriesItemFactory * self = NULL;
#line 25 "/home/gwen/Programmation/vala/shelfpanel/lib/Factories/ItemFactory.vala"
	self = (ShelfpanelFactoriesItemFactory*) g_object_new (object_type, NULL);
#line 25 "/home/gwen/Programmation/vala/shelfpanel/lib/Factories/ItemFactory.vala"
	return self;
#line 63 "ItemFactory.c"
}


ShelfpanelFactoriesItemFactory* shelfpanel_factories_item_factory_new (void) {
#line 25 "/home/gwen/Programmation/vala/shelfpanel/lib/Factories/ItemFactory.vala"
	return shelfpanel_factories_item_factory_construct (SHELFPANEL_FACTORIES_TYPE_ITEM_FACTORY);
#line 70 "ItemFactory.c"
}


static void shelfpanel_factories_item_factory_class_init (ShelfpanelFactoriesItemFactoryClass * klass) {
#line 25 "/home/gwen/Programmation/vala/shelfpanel/lib/Factories/ItemFactory.vala"
	shelfpanel_factories_item_factory_parent_class = g_type_class_peek_parent (klass);
#line 77 "ItemFactory.c"
}


static void shelfpanel_factories_item_factory_instance_init (ShelfpanelFactoriesItemFactory * self) {
}


/**
 * An item factory.  Creates {@link Items.DockItem}s based on .dockitem files.
 */
GType shelfpanel_factories_item_factory_get_type (void) {
	static volatile gsize shelfpanel_factories_item_factory_type_id__volatile = 0;
	if (g_once_init_enter (&shelfpanel_factories_item_factory_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ShelfpanelFactoriesItemFactoryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) shelfpanel_factories_item_factory_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ShelfpanelFactoriesItemFactory), 0, (GInstanceInitFunc) shelfpanel_factories_item_factory_instance_init, NULL };
		GType shelfpanel_factories_item_factory_type_id;
		shelfpanel_factories_item_factory_type_id = g_type_register_static (G_TYPE_OBJECT, "ShelfpanelFactoriesItemFactory", &g_define_type_info, 0);
		g_once_init_leave (&shelfpanel_factories_item_factory_type_id__volatile, shelfpanel_factories_item_factory_type_id);
	}
	return shelfpanel_factories_item_factory_type_id__volatile;
}


