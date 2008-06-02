// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/table.h>
#include <gtkmm/private/table_p.h>

// -*- c++ -*-
/* $Id$ */

/* 
 *
 * Copyright 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <gtk/gtktable.h>

namespace Gtk
{

namespace Table_Helpers
{

Widget* Child::get_widget() const
{
  return Glib::wrap(gobj()->widget);
}

guint16 Child::get_left_attach() const
{
  return gobj()->left_attach;
}


guint16 Child::get_right_attach() const
{
  return gobj()->right_attach;
}

guint16 Child::get_top_attach() const
{
  return gobj()->top_attach;
}

guint16 Child::get_bottom_attach() const
{
  return gobj()->bottom_attach;
}

guint16 Child::get_xpadding() const
{
  return gobj()->xpadding;
}

guint16 Child::get_ypadding() const
{
  return gobj()->ypadding;
}

bool Child::get_xexpand() const
{
  return (bool)gobj()->xexpand;
}

bool Child::get_yexpand() const
{
  return (bool)gobj()->yexpand;
}

bool Child::get_xshrink() const
{
  return (bool)gobj()->xshrink;
}
bool Child::get_yshrink() const
{
  return (bool)gobj()->yshrink;
}

bool Child::get_xfill() const
{
  return (bool)gobj()->xfill;
}

bool Child::get_yfill() const
{
  return (bool)gobj()->yfill;
}


} //namespace Table_Helpers


void Table::set_spacings(guint spacing)
{
  set_row_spacings(spacing);
  set_col_spacings(spacing);
}

Table::TableList& Table::children()
{
  children_proxy_ = TableList(gobj());
  return children_proxy_;
}

const Table::TableList& Table::children() const
{
  children_proxy_ = TableList(const_cast<GtkTable*>(gobj()));
  return children_proxy_;
}


} /* namespace Gtk */


namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::Table* wrap(GtkTable* object, bool take_copy)
{
  return dynamic_cast<Gtk::Table *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& Table_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Table_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_table_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  }

  return *this;
}

void Table_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* Table_Class::wrap_new(GObject* o)
{
  return manage(new Table((GtkTable*)(o)));

}


/* The implementation: */

Table::Table(const Glib::ConstructParams& construct_params)
:
  Gtk::Container(construct_params)
{
  }

Table::Table(GtkTable* castitem)
:
  Gtk::Container((GtkContainer*)(castitem))
{
  }

Table::~Table()
{
  destroy_();
}

Table::CppClassType Table::table_class_; // initialize static member

GType Table::get_type()
{
  return table_class_.init().get_type();
}

GType Table::get_base_type()
{
  return gtk_table_get_type();
}


namespace Table_Helpers
{

void TableList::remove(const_reference child)
{
  gtk_container_remove(GTK_CONTAINER(gparent_),
                       (GtkWidget*)(child.get_widget ()->gobj()));
}

void TableList::remove(Widget& widget)
{
  gtk_container_remove(GTK_CONTAINER(gparent_), (GtkWidget*)(widget.gobj()));
}

TableList::iterator TableList::erase(iterator position)
{
  //Check that it is a valid iterator, to a real item:
  if ( !position.node_|| (position == end()) )
    return end();

  //Get an iterator the the next item, to return:
  iterator next = position;
  next++;

  //Use GTK+ C function to remove it, by providing the GtkWidget*:
  gtk_container_remove( GTK_CONTAINER(gparent_), (GtkWidget*)(position->get_widget ()->gobj()) );
  return next;
}

} /* namespace Table_Helpers */


namespace Table_Helpers
{

TableList::TableList()
{}

TableList::TableList(GtkTable* gparent)
: type_base((GObject*)gparent)
{}

TableList::TableList(const TableList& src)
:
  type_base(src)
{}

TableList& TableList::operator=(const TableList& src)
{
  type_base::operator=(src);
  return *this;
}

GList*& TableList::glist() const
{
  return ((GtkTable*)gparent_)->children;
}

void TableList::erase(iterator start, iterator stop)
{
  type_base::erase(start, stop);
}

GtkTable* TableList::gparent()
{
  return (GtkTable*)type_base::gparent();
}

const GtkTable* TableList::gparent() const
{
  return (GtkTable*)type_base::gparent();
}

TableList::reference TableList::operator[](size_type l) const
{
  return type_base::operator[](l);
}

} /* namespace Table_Helpers */

Table::Table(guint n_rows, guint n_columns, bool homogeneous)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Container(Glib::ConstructParams(table_class_.init(), "n_rows", n_rows, "n_columns", n_columns, "homogeneous", static_cast<int>(homogeneous), static_cast<char*>(0)))
{
  }

void Table::attach(Widget& child, guint left_attach, guint right_attach, guint top_attach, guint bottom_attach, AttachOptions xoptions, AttachOptions yoptions, guint xpadding, guint ypadding)
{
gtk_table_attach(gobj(), (child).gobj(), left_attach, right_attach, top_attach, bottom_attach, ((GtkAttachOptions)(xoptions)), ((GtkAttachOptions)(yoptions)), xpadding, ypadding); 
}

void Table::resize(guint rows, guint columns)
{
gtk_table_resize(gobj(), rows, columns); 
}

void Table::set_row_spacing(guint row, guint spacing)
{
gtk_table_set_row_spacing(gobj(), row, spacing); 
}

guint Table::get_row_spacing(guint row) const
{
  return gtk_table_get_row_spacing(const_cast<GtkTable*>(gobj()), row);
}

void Table::set_col_spacing(guint column, guint spacing)
{
gtk_table_set_col_spacing(gobj(), column, spacing); 
}

guint Table::get_col_spacing(guint column) const
{
  return gtk_table_get_col_spacing(const_cast<GtkTable*>(gobj()), column);
}

void Table::set_row_spacings(guint spacing)
{
gtk_table_set_row_spacings(gobj(), spacing); 
}

void Table::set_col_spacings(guint spacing)
{
gtk_table_set_col_spacings(gobj(), spacing); 
}

guint Table::get_default_row_spacing()
{
  return gtk_table_get_default_row_spacing(gobj());
}

guint Table::get_default_col_spacing()
{
  return gtk_table_get_default_col_spacing(gobj());
}

void Table::set_homogeneous(bool homogeneous)
{
gtk_table_set_homogeneous(gobj(), static_cast<int>(homogeneous)); 
}

bool Table::get_homogeneous() const
{
  return gtk_table_get_homogeneous(const_cast<GtkTable*>(gobj()));
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<guint> Table::property_n_rows() 
{
  return Glib::PropertyProxy<guint>(this, "n-rows");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<guint> Table::property_n_rows() const
{
  return Glib::PropertyProxy_ReadOnly<guint>(this, "n-rows");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<guint> Table::property_n_columns() 
{
  return Glib::PropertyProxy<guint>(this, "n-columns");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<guint> Table::property_n_columns() const
{
  return Glib::PropertyProxy_ReadOnly<guint>(this, "n-columns");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<guint> Table::property_column_spacing() 
{
  return Glib::PropertyProxy<guint>(this, "column-spacing");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<guint> Table::property_column_spacing() const
{
  return Glib::PropertyProxy_ReadOnly<guint>(this, "column-spacing");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<guint> Table::property_row_spacing() 
{
  return Glib::PropertyProxy<guint>(this, "row-spacing");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<guint> Table::property_row_spacing() const
{
  return Glib::PropertyProxy_ReadOnly<guint>(this, "row-spacing");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk


