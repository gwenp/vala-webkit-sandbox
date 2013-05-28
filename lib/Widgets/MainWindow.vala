//
//  Copyright (C) 2011-2012 Robert Dyer, Michal Hruby, Rico Tzschichholz
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

using Cairo;
using Gdk;
using Gee;
using Gtk;
using WebKit;

using Valawebkitsandbox.Factories;

namespace Valawebkitsandbox.Widgets
{
    WebView? view = null;
    Gtk.ScrolledWindow? scrolled = null;
	Gtk.Box? box = null;
	Gtk.Button? buttonRefresh = null;

	/**
	 * The main window for all docks.
	 */
	public class MainWindow : Gtk.Window
	{

		/**
		 * The controller for this dock.
		 */
		public MainController controller { private get; construct; }
		
		/**
		 * Creates a new dock window.
		 */
		public MainWindow (MainController controller)
		{
			GLib.Object (controller: controller, type: Gtk.WindowType.TOPLEVEL);
		}
		
		construct
		{
			box = new Box(Gtk.Orientation.VERTICAL, 0);
    		view = new WebView ();
    		buttonRefresh = new Gtk.Button();
    		buttonRefresh.set_label("Refresh");

    		scrolled = new Gtk.ScrolledWindow (null, null);
    		scrolled.add (view);

    		box.pack_start(buttonRefresh,false,false);
    		box.pack_start(scrolled);
    		add(box);
            view.load_uri ("http://www.google.fr");

    		show_all();
    		resize(500,500);
		}
		
		~MainWindow ()
		{
		}
		
	}
}
