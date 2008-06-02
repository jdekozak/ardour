// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/radiobutton.h>
#include <gtkmm/private/radiobutton_p.h>

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

#include <gtk/gtkradiobutton.h>

typedef Gtk::RadioButton::Group Group; //So that the generate get_group return type is parsed.

namespace Gtk
{

RadioButton::RadioButton()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::CheckButton(Glib::ConstructParams(radiobutton_class_.init()))
{}

RadioButton::RadioButton(const Glib::ustring& label, bool mnemonic)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::CheckButton(Glib::ConstructParams(radiobutton_class_.init(), "label",label.c_str(),"use_underline",gboolean(mnemonic), static_cast<char*>(0)))
{}

RadioButton::RadioButton(Group& group)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::CheckButton(Glib::ConstructParams(radiobutton_class_.init()))
{
  group.add(*this);
}

RadioButton::RadioButton(Group& group, const Glib::ustring& label, bool mnemonic)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::CheckButton(Glib::ConstructParams(radiobutton_class_.init(), "label",label.c_str(),"use_underline",gboolean(mnemonic), static_cast<char*>(0)))
{
  group.add(*this);
}

void RadioButton::set_group(Group& group)
{
  gtk_radio_button_set_group(gobj(), group.group_);

  //The group will be updated, ready for use with the next radiobutton:
  group = get_group();
}

void RadioButton::reset_group()
{
  gtk_radio_button_set_group(gobj(), 0);
}

} //namespace Gtk


namespace
{


static const Glib::SignalProxyInfo RadioButton_signal_group_changed_info =
{
  "group_changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

Gtk::RadioButton* wrap(GtkRadioButton* object, bool take_copy)
{
  return dynamic_cast<Gtk::RadioButton *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& RadioButton_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &RadioButton_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_radio_button_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  }

  return *this;
}

void RadioButton_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  klass->group_changed = &group_changed_callback;
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void RadioButton_Class::group_changed_callback(GtkRadioButton* self)
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
        obj->on_group_changed();
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
  if(base && base->group_changed)
    (*base->group_changed)(self);
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* RadioButton_Class::wrap_new(GObject* o)
{
  return manage(new RadioButton((GtkRadioButton*)(o)));

}


/* The implementation: */

RadioButton::RadioButton(const Glib::ConstructParams& construct_params)
:
  Gtk::CheckButton(construct_params)
{
  }

RadioButton::RadioButton(GtkRadioButton* castitem)
:
  Gtk::CheckButton((GtkCheckButton*)(castitem))
{
  }

RadioButton::~RadioButton()
{
  destroy_();
}

RadioButton::CppClassType RadioButton::radiobutton_class_; // initialize static member

GType RadioButton::get_type()
{
  return radiobutton_class_.init().get_type();
}

GType RadioButton::get_base_type()
{
  return gtk_radio_button_get_type();
}


Group RadioButton::get_group()
{
  return Group(gtk_radio_button_get_group(gobj()));
}


Glib::SignalProxy0< void > RadioButton::signal_group_changed()
{
  return Glib::SignalProxy0< void >(this, &RadioButton_signal_group_changed_info);
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void Gtk::RadioButton::on_group_changed()
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->group_changed)
    (*base->group_changed)(gobj());
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk


