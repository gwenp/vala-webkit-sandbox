/* PlankMain.c generated by valac 0.20.1, the Vala compiler
 * generated from PlankMain.vala, do not modify */

/**/
/*  Copyright (C) 2011-2012 Robert Dyer, Rico Tzschichholz*/
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
#include "shelfpanel.h"
#include <stdlib.h>
#include <string.h>
#include "config.h"


#define SHELFPANEL_TYPE_SHELFPANEL_MAIN (shelfpanel_shelfpanel_main_get_type ())
#define SHELFPANEL_SHELFPANEL_MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SHELFPANEL_TYPE_SHELFPANEL_MAIN, ShelfpanelShelfpanelMain))
#define SHELFPANEL_SHELFPANEL_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SHELFPANEL_TYPE_SHELFPANEL_MAIN, ShelfpanelShelfpanelMainClass))
#define SHELFPANEL_IS_SHELFPANEL_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SHELFPANEL_TYPE_SHELFPANEL_MAIN))
#define SHELFPANEL_IS_SHELFPANEL_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SHELFPANEL_TYPE_SHELFPANEL_MAIN))
#define SHELFPANEL_SHELFPANEL_MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SHELFPANEL_TYPE_SHELFPANEL_MAIN, ShelfpanelShelfpanelMainClass))

typedef struct _ShelfpanelShelfpanelMain ShelfpanelShelfpanelMain;
typedef struct _ShelfpanelShelfpanelMainClass ShelfpanelShelfpanelMainClass;
typedef struct _ShelfpanelShelfpanelMainPrivate ShelfpanelShelfpanelMainPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ShelfpanelShelfpanelMain {
	ShelfpanelFactoriesAbstractMain parent_instance;
	ShelfpanelShelfpanelMainPrivate * priv;
};

struct _ShelfpanelShelfpanelMainClass {
	ShelfpanelFactoriesAbstractMainClass parent_class;
};


static gpointer shelfpanel_shelfpanel_main_parent_class = NULL;

GType shelfpanel_shelfpanel_main_get_type (void) G_GNUC_CONST;
enum  {
	SHELFPANEL_SHELFPANEL_MAIN_DUMMY_PROPERTY
};
gint shelfpanel_shelfpanel_main_main (gchar** args, int args_length1);
ShelfpanelShelfpanelMain* shelfpanel_shelfpanel_main_new (void);
ShelfpanelShelfpanelMain* shelfpanel_shelfpanel_main_construct (GType object_type);


gint shelfpanel_shelfpanel_main_main (gchar** args, int args_length1) {
	gint result = 0;
	ShelfpanelShelfpanelMain* _tmp0_;
	ShelfpanelShelfpanelMain* main_class;
	gint _tmp1_ = 0;
#line 26 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	_tmp0_ = shelfpanel_shelfpanel_main_new ();
#line 26 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	main_class = _tmp0_;
#line 27 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	shelfpanel_factories_factory_init ((ShelfpanelFactoriesAbstractMain*) main_class);
#line 28 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	_tmp1_ = shelfpanel_factories_abstract_main_run ((ShelfpanelFactoriesAbstractMain*) main_class, &args, &args_length1);
#line 28 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	result = _tmp1_;
#line 28 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	_g_object_unref0 (main_class);
#line 28 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	return result;
#line 83 "PlankMain.c"
}


int main (int argc, char ** argv) {
#line 24 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	g_type_init ();
#line 24 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	return shelfpanel_shelfpanel_main_main (argv, argc);
#line 92 "PlankMain.c"
}


ShelfpanelShelfpanelMain* shelfpanel_shelfpanel_main_construct (GType object_type) {
	ShelfpanelShelfpanelMain * self = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
#line 31 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	self = (ShelfpanelShelfpanelMain*) shelfpanel_factories_abstract_main_construct (object_type);
#line 33 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	_tmp0_ = g_strdup (PKGDATADIR);
#line 33 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	_g_free0 (((ShelfpanelFactoriesAbstractMain*) self)->build_pkg_data_dir);
#line 33 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	((ShelfpanelFactoriesAbstractMain*) self)->build_pkg_data_dir = _tmp0_;
#line 35 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	_tmp1_ = g_strdup ("Shelfpanel");
#line 35 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	_g_free0 (((ShelfpanelFactoriesAbstractMain*) self)->program_name);
#line 35 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	((ShelfpanelFactoriesAbstractMain*) self)->program_name = _tmp1_;
#line 36 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	_tmp2_ = g_strdup ("shelf");
#line 36 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	_g_free0 (((ShelfpanelFactoriesAbstractMain*) self)->exec_name);
#line 36 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	((ShelfpanelFactoriesAbstractMain*) self)->exec_name = _tmp2_;
#line 31 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	return self;
#line 123 "PlankMain.c"
}


ShelfpanelShelfpanelMain* shelfpanel_shelfpanel_main_new (void) {
#line 31 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	return shelfpanel_shelfpanel_main_construct (SHELFPANEL_TYPE_SHELFPANEL_MAIN);
#line 130 "PlankMain.c"
}


static void shelfpanel_shelfpanel_main_class_init (ShelfpanelShelfpanelMainClass * klass) {
#line 22 "/home/gwen/Programmation/vala/shelfpanel/src/PlankMain.vala"
	shelfpanel_shelfpanel_main_parent_class = g_type_class_peek_parent (klass);
#line 137 "PlankMain.c"
}


static void shelfpanel_shelfpanel_main_instance_init (ShelfpanelShelfpanelMain * self) {
}


GType shelfpanel_shelfpanel_main_get_type (void) {
	static volatile gsize shelfpanel_shelfpanel_main_type_id__volatile = 0;
	if (g_once_init_enter (&shelfpanel_shelfpanel_main_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ShelfpanelShelfpanelMainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) shelfpanel_shelfpanel_main_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ShelfpanelShelfpanelMain), 0, (GInstanceInitFunc) shelfpanel_shelfpanel_main_instance_init, NULL };
		GType shelfpanel_shelfpanel_main_type_id;
		shelfpanel_shelfpanel_main_type_id = g_type_register_static (SHELFPANEL_FACTORIES_TYPE_ABSTRACT_MAIN, "ShelfpanelShelfpanelMain", &g_define_type_info, 0);
		g_once_init_leave (&shelfpanel_shelfpanel_main_type_id__volatile, shelfpanel_shelfpanel_main_type_id);
	}
	return shelfpanel_shelfpanel_main_type_id__volatile;
}



