// Generated by gtkmmproc -- DO NOT MODIFY!


#include <pangomm/layout.h>
#include <pangomm/private/layout_p.h>

#include <pango/pango-enum-types.h>
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

#include <pango/pangocairo.h>

namespace Pango
{

Layout::Layout(const Glib::RefPtr<Context>& context)
:
  Glib::Object(G_OBJECT(pango_layout_new(context->gobj())))
{}

Glib::RefPtr<Layout> Layout::create(const Cairo::RefPtr<Cairo::Context>& context)
{
  return Glib::wrap( pango_cairo_create_layout(context->cobj()) );
}

void Layout::update_from_cairo_context(const Cairo::RefPtr<Cairo::Context>& context)
{
  pango_cairo_update_layout(context->cobj(), gobj());
}

void Layout::set_text(const Glib::ustring& text)
{
  pango_layout_set_text(gobj(), text.c_str(), text.bytes());
}

void Layout::set_markup(const Glib::ustring& markup)
{
  return pango_layout_set_markup(gobj(), markup.c_str(), markup.bytes());
}

void Layout::set_markup(const Glib::ustring& markup, gunichar accel_marker, gunichar& accel_char)
{
  return pango_layout_set_markup_with_accel(gobj(), markup.c_str(), markup.bytes(), accel_marker, &accel_char);
}

Glib::ArrayHandle<PangoLogAttr> Layout::get_log_attrs() const
{
  //Get array:
  PangoLogAttr* pAttrs = 0;
  int n_attrs = 0;
  pango_layout_get_log_attrs(const_cast<PangoLayout*>(gobj()), &pAttrs, &n_attrs);

  return Glib::ArrayHandle<PangoLogAttr>(pAttrs, n_attrs, Glib::OWNERSHIP_SHALLOW);
}

Rectangle Layout::index_to_pos(int index) const
{
  Rectangle pos;
  pango_layout_index_to_pos(const_cast<PangoLayout*>(gobj()), index, pos.gobj());
  return pos;
}

Rectangle Layout::get_cursor_strong_pos(int index) const
{
  Rectangle strong_pos;
  pango_layout_get_cursor_pos(const_cast<PangoLayout*>(gobj()), index, strong_pos.gobj(), 0);
  return strong_pos;
}

Rectangle Layout::get_cursor_weak_pos(int index) const
{
  Rectangle weak_pos;
  pango_layout_get_cursor_pos(const_cast<PangoLayout*>(gobj()), index, 0, weak_pos.gobj());
  return weak_pos;
}

Rectangle Layout::get_ink_extents() const
{
  Rectangle ink_extents;
  pango_layout_get_extents(const_cast<PangoLayout*>(gobj()), ink_extents.gobj(), 0);
  return ink_extents;
}

Rectangle Layout::get_logical_extents() const
{
  Rectangle logical_extents;
  pango_layout_get_extents(const_cast<PangoLayout*>(gobj()), 0, logical_extents.gobj());
  return logical_extents;
}

Rectangle Layout::get_pixel_ink_extents() const
{
  Rectangle ink_extents;
  pango_layout_get_pixel_extents(const_cast<PangoLayout*>(gobj()), ink_extents.gobj(), 0);
  return ink_extents;
}

Rectangle Layout::get_pixel_logical_extents() const
{
  Rectangle logical_extents;
  pango_layout_get_pixel_extents(const_cast<PangoLayout*>(gobj()), 0, logical_extents.gobj());
  return logical_extents;
}

void Layout::get_iter(LayoutIter& iter)
{
  iter.assign_gobj(pango_layout_get_iter(gobj()));
}

void Layout::unset_font_description()
{
  pango_layout_set_font_description(gobj(), 0);
}

void Layout::add_to_cairo_context(const Cairo::RefPtr<Cairo::Context>& context)
{
  pango_cairo_layout_path(context->cobj(), gobj());
}

} /* namespace Pango */

namespace
{
} // anonymous namespace

// static
GType Glib::Value<Pango::Alignment>::value_type()
{
  return pango_alignment_get_type();
}

// static
GType Glib::Value<Pango::WrapMode>::value_type()
{
  return pango_wrap_mode_get_type();
}

// static
GType Glib::Value<Pango::EllipsizeMode>::value_type()
{
  return pango_ellipsize_mode_get_type();
}


namespace Glib
{

Glib::RefPtr<Pango::Layout> wrap(PangoLayout* object, bool take_copy)
{
  return Glib::RefPtr<Pango::Layout>( dynamic_cast<Pango::Layout*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Pango
{


/* The *_Class implementation: */

const Glib::Class& Layout_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Layout_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(pango_layout_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  }

  return *this;
}

void Layout_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* Layout_Class::wrap_new(GObject* object)
{
  return new Layout((PangoLayout*)object);
}


/* The implementation: */

PangoLayout* Layout::gobj_copy()
{
  reference();
  return gobj();
}

Layout::Layout(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{}

Layout::Layout(PangoLayout* castitem)
:
  Glib::Object((GObject*)(castitem))
{}

Layout::~Layout()
{}


Layout::CppClassType Layout::layout_class_; // initialize static member

GType Layout::get_type()
{
  return layout_class_.init().get_type();
}

GType Layout::get_base_type()
{
  return pango_layout_get_type();
}


Glib::RefPtr<Layout> Layout::create(const Glib::RefPtr<Context>& context)
{
  return Glib::RefPtr<Layout>( new Layout(context) );
}
Glib::RefPtr<Layout> Layout::copy()
{
  return Glib::wrap(pango_layout_copy(gobj()));
}

Glib::RefPtr<Context> Layout::get_context() const
{

  Glib::RefPtr<Context> retvalue = Glib::wrap(pango_layout_get_context(const_cast<PangoLayout*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;

}

void Layout::set_attributes(AttrList& attrs)
{
pango_layout_set_attributes(gobj(), (attrs).gobj()); 
}

AttrList Layout::get_attributes() const
{
  return AttrList((pango_layout_get_attributes(const_cast<PangoLayout*>(gobj()))));
}

Glib::ustring Layout::get_text() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(pango_layout_get_text(const_cast<PangoLayout*>(gobj())));
}

void Layout::set_font_description(const FontDescription& desc)
{
pango_layout_set_font_description(gobj(), (desc).gobj()); 
}

FontDescription Layout::get_font_description() const
{
  return FontDescription(const_cast<PangoFontDescription*>(pango_layout_get_font_description(const_cast<PangoLayout*>(gobj()))));
}

void Layout::set_width(int width)
{
pango_layout_set_width(gobj(), width); 
}

int Layout::get_width() const
{
  return pango_layout_get_width(const_cast<PangoLayout*>(gobj()));
}

void Layout::set_wrap(WrapMode wrap)
{
pango_layout_set_wrap(gobj(), ((PangoWrapMode)(wrap))); 
}

WrapMode Layout::get_wrap() const
{
  return ((WrapMode)(pango_layout_get_wrap(const_cast<PangoLayout*>(gobj()))));
}

bool Layout::is_wrapped() const
{
  return pango_layout_is_wrapped(const_cast<PangoLayout*>(gobj()));
}

void Layout::set_indent(int indent)
{
pango_layout_set_indent(gobj(), indent); 
}

int Layout::get_indent() const
{
  return pango_layout_get_indent(const_cast<PangoLayout*>(gobj()));
}

void Layout::set_spacing(int spacing)
{
pango_layout_set_spacing(gobj(), spacing); 
}

int Layout::get_spacing() const
{
  return pango_layout_get_spacing(const_cast<PangoLayout*>(gobj()));
}

void Layout::set_justify(bool justify)
{
pango_layout_set_justify(gobj(), static_cast<int>(justify)); 
}

bool Layout::get_justify() const
{
  return pango_layout_get_justify(const_cast<PangoLayout*>(gobj()));
}

bool Layout::get_auto_dir() const
{
  return pango_layout_get_auto_dir(const_cast<PangoLayout*>(gobj()));
}

void Layout::set_auto_dir(bool auto_dir)
{
pango_layout_set_auto_dir(gobj(), static_cast<int>(auto_dir)); 
}

void Layout::set_alignment(Alignment alignment)
{
pango_layout_set_alignment(gobj(), ((PangoAlignment)(alignment))); 
}

Alignment Layout::get_alignment() const
{
  return ((Alignment)(pango_layout_get_alignment(const_cast<PangoLayout*>(gobj()))));
}

void Layout::set_tabs(TabArray& tabs)
{
pango_layout_set_tabs(gobj(), (tabs).gobj()); 
}

TabArray Layout::get_tabs() const
{
  return TabArray((pango_layout_get_tabs(const_cast<PangoLayout*>(gobj()))));
}

void Layout::set_single_paragraph_mode(bool setting)
{
pango_layout_set_single_paragraph_mode(gobj(), static_cast<int>(setting)); 
}

bool Layout::get_single_paragraph_mode() const
{
  return pango_layout_get_single_paragraph_mode(const_cast<PangoLayout*>(gobj()));
}

void Layout::set_ellipsize(EllipsizeMode ellipsize)
{
pango_layout_set_ellipsize(gobj(), ((PangoEllipsizeMode)(ellipsize))); 
}

EllipsizeMode Layout::get_ellipsize() const
{
  return ((EllipsizeMode)(pango_layout_get_ellipsize(const_cast<PangoLayout*>(gobj()))));
}

bool Layout::is_ellipsized() const
{
  return pango_layout_is_ellipsized(const_cast<PangoLayout*>(gobj()));
}

int Layout::get_unknown_glyphs_count() const
{
  return pango_layout_get_unknown_glyphs_count(const_cast<PangoLayout*>(gobj()));
}

void Layout::context_changed()
{
pango_layout_context_changed(gobj()); 
}

void Layout::index_to_line_x(int index_, bool trailing, int& line, int& x_pos) const
{
pango_layout_index_to_line_x(const_cast<PangoLayout*>(gobj()), index_, static_cast<int>(trailing), &line, &x_pos); 
}

void Layout::get_cursor_pos(int index, Rectangle& strong_pos, Rectangle& weak_pos) const
{
pango_layout_get_cursor_pos(const_cast<PangoLayout*>(gobj()), index, (strong_pos).gobj(), (weak_pos).gobj()); 
}

void Layout::move_cursor_visually(bool strong, int old_index, int old_trailing, int direction, int& new_index, int& new_trailing) const
{
pango_layout_move_cursor_visually(const_cast<PangoLayout*>(gobj()), static_cast<int>(strong), old_index, old_trailing, direction, &new_index, &new_trailing); 
}

bool Layout::xy_to_index(int x, int y, int& index, int& trailing) const
{
  return pango_layout_xy_to_index(const_cast<PangoLayout*>(gobj()), x, y, &index, &trailing);
}

void Layout::get_extents(Rectangle& ink_rect, Rectangle& logical_rect) const
{
pango_layout_get_extents(const_cast<PangoLayout*>(gobj()), (ink_rect).gobj(), (logical_rect).gobj()); 
}

void Layout::get_pixel_extents(Rectangle& ink_rect, Rectangle& logical_rect) const
{
pango_layout_get_pixel_extents(const_cast<PangoLayout*>(gobj()), (ink_rect).gobj(), (logical_rect).gobj()); 
}

void Layout::get_size(int& width, int& height) const
{
pango_layout_get_size(const_cast<PangoLayout*>(gobj()), &width, &height); 
}

void Layout::get_pixel_size(int& width, int& height) const
{
pango_layout_get_pixel_size(const_cast<PangoLayout*>(gobj()), &width, &height); 
}

int Layout::get_line_count() const
{
  return pango_layout_get_line_count(const_cast<PangoLayout*>(gobj()));
}

Glib::RefPtr<LayoutLine> Layout::get_line(int line)
{

  Glib::RefPtr<LayoutLine> retvalue = Glib::wrap(pango_layout_get_line(gobj(), line));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;

}

Glib::RefPtr<const LayoutLine> Layout::get_line(int line) const
{

  Glib::RefPtr<const LayoutLine> retvalue = Glib::wrap(pango_layout_get_line_readonly(const_cast<PangoLayout*>(gobj()), line));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;

}

SListHandle_LayoutLine Layout::get_lines()
{
  return SListHandle_LayoutLine(pango_layout_get_lines(gobj()), Glib::OWNERSHIP_SHALLOW);
}

SListHandle_ConstLayoutLine Layout::get_lines() const
{
  return SListHandle_ConstLayoutLine(pango_layout_get_lines_readonly(const_cast<PangoLayout*>(gobj())), Glib::OWNERSHIP_SHALLOW);
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Pango


