// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/cellrendereraccel.h>
#include <gtkmm/private/cellrendereraccel_p.h>

// -*- c++ -*-
/* $Id: cellrendereraccel.ccg,v 1.2 2006/05/11 11:40:24 murrayc Exp $ */

/* 
 *
 * Copyright 2005 The gtkmm Development Team
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
 
#include <gtk/gtkcellrendereraccel.h>

namespace Gtk
{

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_Base CellRendererAccel::_property_renderable()
{
  //Renderering just this one property would probably not be meaningful.
  return property_accel_key();
}
#endif //GLIBMM_PROPERTIES_ENABLED

} //namespace Gtk

namespace
{


static void CellRendererAccel_signal_accel_edited_callback(GtkCellRendererAccel* self, const gchar* p0,guint p1,GdkModifierType p2,guint p3,void* data)
{
  using namespace Gtk;
  typedef sigc::slot< void,const Glib::ustring&,guint,Gdk::ModifierType,guint > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
, p1, ((Gdk::ModifierType)(p2))
, p3);
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
    #endif //GLIBMM_EXCEPTIONS_ENABLED
  }
}

static const Glib::SignalProxyInfo CellRendererAccel_signal_accel_edited_info =
{
  "accel_edited",
  (GCallback) &CellRendererAccel_signal_accel_edited_callback,
  (GCallback) &CellRendererAccel_signal_accel_edited_callback
};


static void CellRendererAccel_signal_accel_cleared_callback(GtkCellRendererAccel* self, const gchar* p0,void* data)
{
  using namespace Gtk;
  typedef sigc::slot< void,const Glib::ustring& > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
    #endif //GLIBMM_EXCEPTIONS_ENABLED
  }
}

static const Glib::SignalProxyInfo CellRendererAccel_signal_accel_cleared_info =
{
  "accel_cleared",
  (GCallback) &CellRendererAccel_signal_accel_cleared_callback,
  (GCallback) &CellRendererAccel_signal_accel_cleared_callback
};


} // anonymous namespace


namespace Glib
{

Gtk::CellRendererAccel* wrap(GtkCellRendererAccel* object, bool take_copy)
{
  return dynamic_cast<Gtk::CellRendererAccel *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& CellRendererAccel_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellRendererAccel_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_renderer_accel_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  }

  return *this;
}

void CellRendererAccel_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  klass->accel_edited = &accel_edited_callback;
  klass->accel_cleared = &accel_cleared_callback;
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void CellRendererAccel_Class::accel_edited_callback(GtkCellRendererAccel* self, const gchar* p0, guint p1, GdkModifierType p2, guint p3)
{
  Glib::ObjectBase *const obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    CppObjectType *const obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_accel_edited(Glib::convert_const_gchar_ptr_to_ustring(p0)
, p1, ((Gdk::ModifierType)(p2))
, p3);
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }
  
  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->accel_edited)
    (*base->accel_edited)(self, p0, p1, p2, p3);
}
void CellRendererAccel_Class::accel_cleared_callback(GtkCellRendererAccel* self, const gchar* p0)
{
  Glib::ObjectBase *const obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    CppObjectType *const obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_accel_cleared(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }
  
  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->accel_cleared)
    (*base->accel_cleared)(self, p0);
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* CellRendererAccel_Class::wrap_new(GObject* o)
{
  return manage(new CellRendererAccel((GtkCellRendererAccel*)(o)));

}


/* The implementation: */

CellRendererAccel::CellRendererAccel(const Glib::ConstructParams& construct_params)
:
  Gtk::CellRendererText(construct_params)
{
  }

CellRendererAccel::CellRendererAccel(GtkCellRendererAccel* castitem)
:
  Gtk::CellRendererText((GtkCellRendererText*)(castitem))
{
  }

CellRendererAccel::~CellRendererAccel()
{
  destroy_();
}

CellRendererAccel::CppClassType CellRendererAccel::cellrendereraccel_class_; // initialize static member

GType CellRendererAccel::get_type()
{
  return cellrendereraccel_class_.init().get_type();
}

GType CellRendererAccel::get_base_type()
{
  return gtk_cell_renderer_accel_get_type();
}


CellRendererAccel::CellRendererAccel()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::CellRendererText(Glib::ConstructParams(cellrendereraccel_class_.init()))
{
  }


Glib::SignalProxy4< void,const Glib::ustring&,guint,Gdk::ModifierType,guint > CellRendererAccel::signal_accel_edited()
{
  return Glib::SignalProxy4< void,const Glib::ustring&,guint,Gdk::ModifierType,guint >(this, &CellRendererAccel_signal_accel_edited_info);
}


Glib::SignalProxy1< void,const Glib::ustring& > CellRendererAccel::signal_accel_cleared()
{
  return Glib::SignalProxy1< void,const Glib::ustring& >(this, &CellRendererAccel_signal_accel_cleared_info);
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<guint> CellRendererAccel::property_accel_key() 
{
  return Glib::PropertyProxy<guint>(this, "accel-key");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<guint> CellRendererAccel::property_accel_key() const
{
  return Glib::PropertyProxy_ReadOnly<guint>(this, "accel-key");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Gdk::ModifierType> CellRendererAccel::property_accel_mods() 
{
  return Glib::PropertyProxy<Gdk::ModifierType>(this, "accel-mods");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Gdk::ModifierType> CellRendererAccel::property_accel_mods() const
{
  return Glib::PropertyProxy_ReadOnly<Gdk::ModifierType>(this, "accel-mods");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<guint> CellRendererAccel::property_keycode() 
{
  return Glib::PropertyProxy<guint>(this, "keycode");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<guint> CellRendererAccel::property_keycode() const
{
  return Glib::PropertyProxy_ReadOnly<guint>(this, "keycode");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void Gtk::CellRendererAccel::on_accel_edited(const Glib::ustring& path_string, guint accel_key, Gdk::ModifierType accel_mods, guint hardware_keycode)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->accel_edited)
    (*base->accel_edited)(gobj(),path_string.c_str(),accel_key,((GdkModifierType)(accel_mods)),hardware_keycode);
}
void Gtk::CellRendererAccel::on_accel_cleared(const Glib::ustring& path_string)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->accel_cleared)
    (*base->accel_cleared)(gobj(),path_string.c_str());
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk


