//
//  Copyright (C) 2011-2012 Gwenaël Pluchon
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

using Valawebkitsandbox.Factories;

namespace AppMain
{
	public class AppMain : AbstractMain
	{
		public static int main (string[] args)
		{
			var main_class = new AppMain ();
			Factory.init (main_class);
			return main_class.run (ref args);
		}
		
		public AppMain ()
		{
			build_pkg_data_dir = Build.PKGDATADIR;
			
			program_name = "Valawebkitsandbox";
			exec_name = "valawebkitsandbox";
		}
	}
}
