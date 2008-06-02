// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_HANDLEBOX_H
#define _GTKMM_HANDLEBOX_H


#include <glibmm.h>

 /* $Id$ */

/* handlebox.h
 * 
 * Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <gtkmm/eventbox.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkHandleBox GtkHandleBox;
typedef struct _GtkHandleBoxClass GtkHandleBoxClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class HandleBox_Class; } // namespace Gtk
namespace Gtk
{

/** A widget for detachable window portions.
 *
 * The Gtk::HandleBox widget allows a portion of a window to be "torn off".
 * It displays its child and a handle that the user can drag to tear off a separate window (the float window) containing the child widget. A thin ghost is drawn in the original location of the handlebox. By dragging the separate window back to its original location, it can be reattached.
 * When reattaching, the ghost and float window must be aligned along one of the edges, the snap edge. This can be specified by the application programmer explicitely, or GTK+ will pick a reasonable default based on the handle position.
 * To make detaching and reattaching the handlebox as minimally confusing as possible to the user, it is important to set the snap edge so that the snap edge does not move when the handlebox is deattached.
 * For instance, if the handlebox is packed at the bottom of a VBox, then when the handlebox is detached, the bottom edge of the handlebox's allocation will remain fixed as the height of the handlebox shrinks, so the snap edge should be set to GTK_POS_BOTTOM.
 *
 * @ingroup Widgets
 * @ingroup Containers
 */

class HandleBox : public Bin
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef HandleBox CppObjectType;
  typedef HandleBox_Class CppClassType;
  typedef GtkHandleBox BaseObjectType;
  typedef GtkHandleBoxClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~HandleBox();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class HandleBox_Class;
  static CppClassType handlebox_class_;

  // noncopyable
  HandleBox(const HandleBox&);
  HandleBox& operator=(const HandleBox&);

protected:
  explicit HandleBox(const Glib::ConstructParams& construct_params);
  explicit HandleBox(GtkHandleBox* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkHandleBox*       gobj()       { return reinterpret_cast<GtkHandleBox*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkHandleBox* gobj() const { return reinterpret_cast<GtkHandleBox*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

protected:
  //GTK+ Virtual Functions (override these to change behaviour):
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

  //Default Signal Handlers::
#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  virtual void on_child_attached(Widget* child);
  virtual void on_child_detached(Widget* child);
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


private:

public:
  HandleBox();
  

  void set_shadow_type(ShadowType type);
  
  /** Gets the type of shadow drawn around the handle box. See
   * set_shadow_type().
   * @return The type of shadow currently drawn around the handle box.
   */
  ShadowType get_shadow_type() const;
  
  void set_handle_position(PositionType position);
  
  /** Gets the handle position of the handle box. See
   * set_handle_position().
   * @return The current handle position.
   */
  PositionType get_handle_position() const;
  
  void set_snap_edge(PositionType edge);
  
  /** Gets the edge used for determining reattachment of the handle box. See
   * set_snap_edge().
   * @return The edge used for determining reattachment, or (GtkPositionType)-1 if this
   * is determined (as per default) from the handle position.
   */
  PositionType get_snap_edge() const;

  
  /**
   * @par Prototype:
   * <tt>void on_my_%child_attached(Widget* child)</tt>
   */

  Glib::SignalProxy1< void,Widget* > signal_child_attached();

  
  /**
   * @par Prototype:
   * <tt>void on_my_%child_detached(Widget* child)</tt>
   */

  Glib::SignalProxy1< void,Widget* > signal_child_detached();


   Glib::RefPtr<Gdk::Window> get_bin_window();
  Glib::RefPtr<const Gdk::Window> get_bin_window() const;
    Glib::RefPtr<Gdk::Window> get_float_window();
  Glib::RefPtr<const Gdk::Window> get_float_window() const;
 
  bool is_child_detached() const;
  bool is_float_window_mapped() const;
  bool is_in_drag() const;
  bool shrinks_on_detach() const;

  //_WRAP_PROPERTY("shadow", ShadowType); //deprecated.
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Appearance of the shadow that surrounds the container.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<ShadowType> property_shadow_type() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Appearance of the shadow that surrounds the container.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<ShadowType> property_shadow_type() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Position of the handle relative to the child widget.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<PositionType> property_handle_position() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Position of the handle relative to the child widget.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<PositionType> property_handle_position() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Side of the handlebox that's lined up with the docking point to dock the handlebox.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<PositionType> property_snap_edge() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Side of the handlebox that's lined up with the docking point to dock the handlebox.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<PositionType> property_snap_edge() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


};

} /* namespace Gtk */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::HandleBox
   */
  Gtk::HandleBox* wrap(GtkHandleBox* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_HANDLEBOX_H */

