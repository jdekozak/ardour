// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GLIBMM_THREAD_H
#define _GLIBMM_THREAD_H


/* $Id: thread.hg,v 1.13 2005/01/21 12:48:05 murrayc Exp $ */

/* Copyright (C) 2002 The gtkmm Development Team
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


#include <glib/gthread.h>
#include <cstddef>

#include <sigc++/sigc++.h>
#include <glibmm/error.h>
#include <glibmm/timeval.h>

/* Shadow THREAD_PRIORITY_NORMAL macro (from winbase.h).
 */
#if defined(THREAD_PRIORITY_NORMAL) && !defined(GLIBMM_MACRO_SHADOW_THREAD_PRIORITY_NORMAL)
enum { GLIBMM_MACRO_DEFINITION_THREAD_PRIORITY_NORMAL = THREAD_PRIORITY_NORMAL };
#undef THREAD_PRIORITY_NORMAL
enum { THREAD_PRIORITY_NORMAL = GLIBMM_MACRO_DEFINITION_THREAD_PRIORITY_NORMAL };
#define THREAD_PRIORITY_NORMAL THREAD_PRIORITY_NORMAL
#define GLIBMM_MACRO_SHADOW_THREAD_PRIORITY_NORMAL 1
#endif


/** Initializer macro for Glib::StaticMutex.
 * @relates Glib::StaticMutex
 * @hideinitializer
 */
#define GLIBMM_STATIC_MUTEX_INIT { G_STATIC_MUTEX_INIT }

/** Initializer macro for Glib::StaticRecMutex.
 * @relates Glib::StaticRecMutex
 * @hideinitializer
 */
#define GLIBMM_STATIC_REC_MUTEX_INIT { G_STATIC_REC_MUTEX_INIT }

/** Initializer macro for Glib::StaticRWLock.
 * @relates Glib::StaticRWLock
 * @hideinitializer
 */
#define GLIBMM_STATIC_RW_LOCK_INIT { G_STATIC_RW_LOCK_INIT }

/** Initializer macro for Glib::StaticPrivate.
 * @relates Glib::StaticPrivate
 * @hideinitializer
 */
#define GLIBMM_STATIC_PRIVATE_INIT { G_STATIC_PRIVATE_INIT }


namespace Glib
{

/** Specifies the priority of a thread.
 * @note It is not guaranteed, that threads with different priorities really
 * behave accordingly. On some systems (e.g. Linux) only <tt>root</tt> can
 * increase priorities. On other systems (e.g. Solaris) there doesn't seem to
 * be different scheduling for different priorities. All in all try to avoid
 * being dependent on priorities.
 */
/** @addtogroup glibmmEnums Enums and Flags */

/**
 * @ingroup glibmmEnums
 */
enum ThreadPriority
{
  THREAD_PRIORITY_LOW,
  THREAD_PRIORITY_NORMAL,
  THREAD_PRIORITY_HIGH,
  THREAD_PRIORITY_URGENT
};


/*! @var ThreadPriority THREAD_PRIORITY_LOW
 * A priority lower than normal.
 */
/*! @var ThreadPriority THREAD_PRIORITY_NORMAL
 * The default priority.
 */
/*! @var ThreadPriority THREAD_PRIORITY_HIGH
 * A priority higher than normal.
 */
/*! @var ThreadPriority THREAD_PRIORITY_URGENT
 * The highest priority.
 */


/** @defgroup Threads Threads
 * Thread abstraction; including threads, different mutexes,
 * conditions and thread private data.
 * @{
 */

enum NotLock { NOT_LOCK };
enum TryLock { TRY_LOCK };

/** Initializes the GLib thread system.
 * Before you use a thread related function in glibmm, you should initialize
 * the thread system.  This is done by calling Glib::thread_init().
 *
 * @note You should only call thread_init() with a non-<tt>0</tt> parameter
 * if you really know what you are doing.
 *
 * @note thread_init() must not be called directly or indirectly as
 * a callback from glibmm.  Also no mutexes may be currently locked while
 * calling thread_init().
 *
 * thread_init() might only be called once.  On the second call it will
 * abort with an error.  If you want to make sure that the thread system
 * is initialized, you can do that too:
 * @code
 * if(!Glib::thread_supported()) Glib::thread_init();
 * @endcode
 * After that line either the thread system is initialized, or the program
 * will abort if no thread system is available in GLib, i.e. either
 * @c G_THREADS_ENABLED is not defined or @c G_THREADS_IMPL_NONE is defined.
 *
 * If no thread system is available and @a vtable is <tt>0</tt> or if not all
 * elements of @a vtable are non-<tt>0</tt>, then thread_init() will abort.
 *
 * @note To use thread_init() in your program, you have to link with the
 * libraries that the command <tt>pkg-config&nbsp;--libs&nbsp;gthread-2.0</tt>
 * outputs.  This is not the case for all the other thread related functions
 * of glibmm.  Those can be used without having to link with the thread
 * libraries.  (You @em have to link with <tt>gthread-2.0</tt> if you actually
 * want to use threads in your application, though.)
 *
 * @param vtable A function table of type @c GThreadFunctions, that provides
 * the entry points to the thread system to be used.
 */
inline void thread_init(GThreadFunctions* vtable = 0);

/** Returns whether the thread system is initialized.
 * @return @c true, if the thread system is initialized.
 */
inline bool thread_supported();


class Mutex;
class RecMutex;
class RWLock;
struct StaticMutex;
struct StaticRecMutex;
struct StaticRWLock;


/** Exception class for thread-related errors.
 */
class ThreadError : public Glib::Error
{
public:
  enum Code
  {
    AGAIN
  };

  ThreadError(Code error_code, const Glib::ustring& error_message);
  explicit ThreadError(GError* gobject);
  Code code() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

#ifdef GLIBMM_EXCEPTIONS_ENABLED
  static void throw_func(GError* gobject);
#else
  //When not using exceptions, we just pass the Exception object around without throwing it:
  static std::auto_ptr<Glib::Error> throw_func(GError* gobject);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  friend void wrap_init(); // uses throw_func()
#endif
};


/** Represents a running thread.
 * An instance of this class can only be obtained with create(), self(),
 * or wrap(GThread*).  It's not possible to delete a Thread object.  If the
 * thread is @em not joinable, its resources will be freed automatically
 * when it exits.  Otherwise, if the thread @em is joinable, you must call
 * join() to avoid a memory leak.
 *
 * @note g_thread_exit() is not wrapped, because that function exits a thread
 * without any cleanup.  That's especially dangerous in C++ code, since the
 * destructors of automatic objects won't be invoked.  Instead, you can throw
 * a Thread::Exit exception, which will be caught by the internal thread
 * entry function.
 *
 * @note You might have noticed that the thread entry slot doesn't have the
 * usual void* return value.  If you want to return any data from your thread
 * you can pass an additional output argument to the thread's entry slot.
 */
class Thread
{
public:
  class Exit;

  /** Creates a new thread with the priority <tt>THREAD_PRIORITY_NORMAL</tt>.
   * If @a joinable is @c true, you can wait for this thread's termination by
   * calling join().  Otherwise the thread will just disappear, when ready.
   *
   * The new thread executes the function or method @a slot points to.  You can
   * pass additional arguments using sigc::bind().  If the thread was created
   * successfully, it is returned, otherwise a ThreadError exception is thrown.
   *
   * @param slot A slot to execute in the new thread.
   * @param joinable Should this thread be joinable?
   * @return The new Thread* on success.
   * @throw Glib::ThreadError
   */
  static Thread* create(const sigc::slot<void>& slot, bool joinable);

  /** Creates a new thread with the priority @a priority. The stack gets the
   * size @a stack_size or the default value for the current platform, if
   * @a stack_size is <tt>0</tt>.
   *
   * If @a joinable is @c true, you can wait for this thread's termination by
   * calling join().  Otherwise the thread will just disappear, when ready.
   * If @a bound is @c true, this thread will be scheduled in the system scope,
   * otherwise the implementation is free to do scheduling in the process
   * scope.  The first variant is more expensive resource-wise, but generally
   * faster.  On some systems (e.g. Linux) all threads are bound.
   *
   * The new thread executes the function or method @a slot points to.  You can
   * pass additional arguments using sigc::bind().  If the thread was created
   * successfully, it is returned.
   *
   * @note It is not guaranteed, that threads with different priorities really
   * behave accordingly.  On some systems (e.g. Linux) only root can increase
   * priorities.  On other systems (e.g. Solaris) there doesn't seem to be
   * different scheduling for different priorities.  All in all try to avoid
   * being dependent on priorities.  Use <tt>Glib::THREAD_PRIORITY_NORMAL</tt>
   * here as a default.
   *
   * @note Only use the extended
   * create(const sigc::slot<void>&, unsigned long, bool, bool, ThreadPriority)
   * function, when you really can't use the simple
   * create(const sigc::slot<void>&, bool)
   * instead.  The latter overload does not take @a stack_size, @a bound and
   * @a priority as arguments, as they should only be used for cases, where
   * it is inevitable.
   *
   * @param slot A slot to execute in the new thread.
   * @param stack_size A stack size for the new thread, or <tt>0</tt>.
   * @param joinable Should this thread be joinable?
   * @param bound Should this thread be bound to a system thread?
   * @param priority A priority for the thread.
   * @return The new Thread* on success.
   * @throw Glib::ThreadError
   */
  static Thread* create(const sigc::slot<void>& slot, unsigned long stack_size,
                        bool joinable, bool bound, ThreadPriority priority);

  /** Returns the Thread* corresponding to the calling thread.
   * @return The current thread.
   */
  static Thread* self();

  /** Returns whether the thread is joinable.
   * @return Whether the thread is joinable.
   */
  bool joinable() const;

  /** Waits until the thread finishes.
   * Waits until the thread finishes, i.e. the slot, as given to create(),
   * returns or g_thread_exit() is called by the thread.  (Calling
   * g_thread_exit() in a C++ program should be avoided.)  All resources of
   * the thread including the Glib::Thread object are released.  The thread
   * must have been created with <tt>joinable&nbsp;=&nbsp;true</tt>.
   */
  void join();

  /** Changes the priority of the thread to @a priority.
   * @note It is not guaranteed, that threads with different priorities really
   * behave accordingly.  On some systems (e.g. Linux) only @c root can
   * increase priorities.  On other systems (e.g. Solaris) there doesn't seem
   * to be different scheduling for different priorities.  All in all try to
   * avoid being dependent on priorities.
   * @param priority A new priority for the thread.
   */
  void set_priority(ThreadPriority priority);

  /** Returns the priority of the thread.
   * @return The thread's priority.
   */
  ThreadPriority get_priority() const;

  /** Gives way to other threads waiting to be scheduled.
   * This function is often used as a method to make busy wait less evil.  But
   * in most cases, you will encounter, there are better methods to do that.
   * So in general you shouldn't use this function.
   */
  static void yield();

  GThread*       gobj()       { return &gobject_; }
  const GThread* gobj() const { return &gobject_; }

private:
  GThread gobject_;

  // Glib::Thread can neither be constructed nor deleted.
  Thread();
  void operator delete(void*, size_t);

  // noncopyable
  Thread(const Thread&);
  Thread& operator=(const Thread&);
};

/** %Exception class used to exit from a thread.
 * @code
 * throw Glib::Thread::Exit();
 * @endcode
 * Write this if you want to exit from a thread created by Thread::create().
 * Of course you must make sure not to catch Thread::Exit by accident, i.e.
 * when using <tt>catch(...)</tt> somewhere in your code.
 */
class Thread::Exit
{};

/** @relates Glib::Thread */
Thread* wrap(GThread* gobject);


/** Like Glib::Mutex, but can be defined at compile time.
 * Use @c GLIBMM_STATIC_MUTEX_INIT to initialize a StaticMutex:
 * @code
 * Glib::StaticMutex mutex = GLIBMM_STATIC_MUTEX_INIT;
 * @endcode
 * A StaticMutex can be used without calling Glib::thread_init(), it will
 * silently do nothing then.  That will also work when using the implicit
 * conversion to Mutex&, thus you can safely use Mutex::Lock with a
 * StaticMutex.
 */
struct StaticMutex
{
  void lock();
  bool trylock();
  void unlock();

  operator Mutex&();

  GStaticMutex* gobj() { return &gobject_; }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  // Must be public to allow initialization at compile time.
  GStaticMutex gobject_;
#endif
};

/** Represents a mutex (mutual exclusion).
 * It can be used to protect data against shared access.  Try to use
 * Mutex::Lock instead of calling lock() and unlock() directly&nbsp;--
 * it will make your life much easier.
 *
 * @note Before creating a Glib::Mutex, Glib::thread_init() has to be called.
 *
 * @note Glib::Mutex is not recursive, i.e. a thread will deadlock, if it
 * already has locked the mutex while calling lock().  Use Glib::RecMutex
 * instead, if you need recursive mutexes.
 */
class Mutex
{
public:
  class Lock;

  Mutex();
  ~Mutex();

  /** Locks the mutex.
   * If mutex is already locked by another thread, the current thread will
   * block until mutex is unlocked by the other thread.
   * @see Mutex::Lock
   */
  void lock();

  /** Tries to lock the mutex.
   * If the mutex is already locked by another thread, it immediately returns
   * @c false.  Otherwise it locks the mutex and returns @c true.
   * @return Whether the mutex could be locked.
   * @see Mutex::Lock
   */
  bool trylock();

  /** Unlocks the mutex.
   * If another thread is blocked in a lock() call for this mutex, it will be
   * woken and can lock the mutex itself.
   * @see Mutex::Lock
   */
  void unlock();

  GMutex* gobj() { return gobject_; }

private:
  GMutex* gobject_;

  // noncopyable
  Mutex(const Mutex&);
  Mutex& operator=(const Mutex&);
};

/** Utility class for exception-safe mutex locking.
 * @par Usage example:
 * @code
 * {
 *   Glib::Mutex::Lock lock (mutex); // calls mutex.lock()
 *   do_something();
 * } // the destructor calls mutex.unlock()
 * @endcode
 * As you can see, the compiler takes care of the unlocking.  This is not
 * only exception safe but also much less error-prone.  You could even
 * <tt>return</tt> while still holding the lock and it will be released
 * properly.
 */
class Mutex::Lock
{
public:
  explicit inline Lock(Mutex& mutex);
  inline Lock(Mutex& mutex, NotLock);
  inline Lock(Mutex& mutex, TryLock);
  inline ~Lock();

  inline void acquire();
  inline bool try_acquire();
  inline void release();
  inline bool locked() const;

private:
  Mutex&  mutex_;
  bool    locked_;

  // noncopyable
  Lock(const Mutex::Lock&);
  Mutex::Lock& operator=(const Mutex::Lock&);
};


/** Like Glib::RecMutex, but can be defined at compile time.
 * Use @c GLIBMM_STATIC_REC_MUTEX_INIT to initialize a StaticRecMutex:
 * @code
 * Glib::StaticRecMutex mutex = GLIBMM_STATIC_REC_MUTEX_INIT;
 * @endcode
 * A StaticRecMutex can be used without calling Glib::thread_init(), it will
 * silently do nothing then.  That will also work when using the implicit
 * conversion to RecMutex&, thus you can safely use RecMutex::Lock with a
 * StaticRecMutex.
 */
struct StaticRecMutex
{
  void lock();
  bool trylock();
  void unlock();

  void lock_full(unsigned int depth);
  unsigned int unlock_full();

  operator RecMutex&();

  GStaticRecMutex* gobj() { return &gobject_; }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  // Must be public to allow initialization at compile time.
  GStaticRecMutex gobject_;
#endif
};

class RecMutex : public StaticRecMutex
{
public:
  class Lock;

  RecMutex();
  ~RecMutex();

private:
  // noncopyable
  RecMutex(const RecMutex&);
  RecMutex& operator=(const RecMutex&);
};

/** Utility class for exception-safe locking of recursive mutexes.
 */
class RecMutex::Lock
{
public:
  explicit inline Lock(RecMutex& mutex);
  inline Lock(RecMutex& mutex, NotLock);
  inline Lock(RecMutex& mutex, TryLock);
  inline ~Lock();

  inline void acquire();
  inline bool try_acquire();
  inline void release();
  inline bool locked() const;

private:
  RecMutex& mutex_;
  bool      locked_;

  // noncopyable
  Lock(const RecMutex::Lock&);
  RecMutex::Lock& operator=(const RecMutex::Lock&);
};


/** Like Glib::RWLock, but can be defined at compile time.
 * Use @c GLIBMM_STATIC_RW_LOCK_INIT to initialize a StaticRWLock:
 * @code
 * Glib::StaticRWLock rw_lock = GLIBMM_STATIC_RW_LOCK_INIT;
 * @endcode
 * A StaticRWLock can be used without calling Glib::thread_init(), it will
 * silently do nothing then.  That will also work when using the implicit
 * conversion to RWLock&, thus you can safely use RWLock::ReaderLock and
 * RWLock::WriterLock with a StaticRWLock.
 */
struct StaticRWLock
{
  void reader_lock();
  bool reader_trylock();
  void reader_unlock();

  void writer_lock();
  bool writer_trylock();
  void writer_unlock();

  operator RWLock&();

  GStaticRWLock* gobj() { return &gobject_; }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  // Must be public to allow initialization at compile time.
  GStaticRWLock gobject_;
#endif
};

class RWLock : public StaticRWLock
{
public:
  class ReaderLock;
  class WriterLock;

  RWLock();
  ~RWLock();

private:
  // noncopyable
  RWLock(const RWLock&);
  RWLock& operator=(const RWLock&);
};

/** Utility class for exception-safe locking of read/write locks.
 */
class RWLock::ReaderLock
{
public:
  explicit inline ReaderLock(RWLock& rwlock);
  inline ReaderLock(RWLock& rwlock, NotLock);
  inline ReaderLock(RWLock& rwlock, TryLock);
  inline ~ReaderLock();

  inline void acquire();
  inline bool try_acquire();
  inline void release();
  inline bool locked() const;

private:
  RWLock& rwlock_;
  bool    locked_;

  // noncopyable
  ReaderLock(const RWLock::ReaderLock&);
  RWLock::ReaderLock& operator=(const RWLock::ReaderLock&);
};

/** Utility class for exception-safe locking of read/write locks.
 */
class RWLock::WriterLock
{
public:
  explicit inline WriterLock(RWLock& rwlock);
  inline WriterLock(RWLock& rwlock, NotLock);
  inline WriterLock(RWLock& rwlock, TryLock);
  inline ~WriterLock();

  inline void acquire();
  inline bool try_acquire();
  inline void release();
  inline bool locked() const;

private:
  RWLock& rwlock_;
  bool    locked_;

  // noncopyable
  WriterLock(const RWLock::WriterLock&);
  RWLock::WriterLock& operator=(const RWLock::WriterLock&);
};

/** An opaque data structure to represent a condition. 
 * A @a Cond is an object that threads can block on, if they find a certain 
 * condition to be false. If other threads change the state of this condition 
 * they can signal the @a Cond, such that the waiting thread is woken up.
 * @par Usage example:
 * @code
 * Glib::Cond data_cond;
 * Glib::Mutex data_mutex;
 * void* current_data = NULL;
 * 
 * void push_data (void* data)
 * {
 *   data_mutex.lock();
 *   current_data = data;
 *   data_cond.signal();
 *   data_mutex.unlock();
 * }
 * 
 * void* pop_data ()
 * {
 *   void* data;
 * 
 *   data_mutex.lock();
 *   while (!current_data)
 *       data_cond.wait(data_mutex);
 *   data = current_data;
 *   current_data = NULL;
 *   data_mutex.unlock();
 *   return data;
 * }
 * @endcode
*/
class Cond
{
public:
  Cond();
  ~Cond();

  /** If threads are waiting for this @a Cond, exactly one of them is woken up. 
   * It is good practice to hold the same lock as the waiting thread, while calling 
   * this method, though not required.
   *
   * @note This method can also be used if @a Glib::thread_init() has not yet been 
   * called and will do nothing then.
   */
  void signal();

  /** If threads are waiting for this @a Cond, all of them are woken up.
   * It is good practice to hold the same lock as the waiting thread, while calling 
   * this method, though not required.
   *
   * @note This method can also be used if @a Glib::thread_init() has not yet been 
   * called and will do nothing then.
   */
  void broadcast();

  /** Waits until this thread is woken up on this @a Cond.
   * The mutex is unlocked before falling asleep and locked again before resuming.
   *
   * This method can also be used if @a Glib::thread_init() has not yet been 
   * called and will immediately return then. 
   *
   * @param mutex a @a Mutex that is currently locked.
   * 
   * @note It is important to use the @a wait() and @a timed_wait() methods
   * only inside a loop, which checks for the condition to be true as it is not 
   * guaranteed that the waiting thread will find it fulfilled, even if the signaling 
   * thread left the condition in that state. This is because another thread can have 
   * altered the condition, before the waiting thread got the chance to be woken up, 
   * even if the condition itself is protected by a @a Mutex.
   */
  void wait(Mutex& mutex);

  /** Waits until this thread is woken up on this @a Cond, but not longer than until the time, that is specified by @a abs_time.
   * The mutex is unlocked before falling asleep and locked again before resuming.
   *
   * This function can also be used, if @a Glib::thread_init() has not yet been 
   * called and will immediately return @c true then. 
   *
   * @param mutex a @a Mutex that is currently locked.
   * @param abs_time a max time to wait.
   * 
   * @note It is important to use the @a wait() and @a timed_wait() methods
   * only inside a loop, which checks for the condition to be true as it is not 
   * guaranteed that the waiting thread will find it fulfilled, even if the signaling 
   * thread left the condition in that state. This is because another thread can have 
   * altered the condition, before the waiting thread got the chance to be woken up, 
   * even if the condition itself is protected by a @a Mutex.
   */
  bool timed_wait(Mutex& mutex, const Glib::TimeVal& abs_time);

  GCond* gobj() { return gobject_; }

private:
  GCond* gobject_;

  // noncopyable
  Cond(const Cond&);
  Cond& operator=(const Cond&);
};


template <class T>
struct StaticPrivate
{
  typedef void (*DestroyNotifyFunc) (void*);

  static void delete_ptr(void* data);

  inline T* get();
  inline void set(T* data, DestroyNotifyFunc notify_func = &StaticPrivate<T>::delete_ptr);

  GStaticPrivate* gobj() { return &gobject_; }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  // Must be public to allow initialization at compile time.
  GStaticPrivate gobject_;
#endif
};

template <class T>
class Private
{
public:
  typedef void (*DestructorFunc) (void*);

  static void delete_ptr(void* data);

  explicit inline Private(DestructorFunc destructor_func = &Private<T>::delete_ptr);
  inline T* get();
  inline void set(T* data);

  GPrivate* gobj() { return gobject_; }

private:
  GPrivate* gobject_;

  // noncopyable
  Private(const Private<T>&);
  Private<T>& operator=(const Private<T>&);
};

/** @} group Threads */

/*! A glibmm thread example.
 * @example thread/thread.cc
 */


#ifndef DOXYGEN_SHOULD_SKIP_THIS

/***************************************************************************/
/*  inline implementation                                                  */
/***************************************************************************/

// internal
void thread_init_impl();

/* This function must be inline, to avoid an unnecessary dependency on
 * libgthread even if the thread system is not used.  libgthread might
 * not even be available if GLib was compiled without thread support.
 */
inline
void thread_init(GThreadFunctions* vtable)
{
  g_thread_init(vtable);
  Glib::thread_init_impl();
}

inline
bool thread_supported()
{
  //MSVC++ needs the != 0 to avoid an int -> bool cast warning.
  return (g_thread_supported() != 0);
}


/**** Glib::Mutex::Lock ****************************************************/

inline
Mutex::Lock::Lock(Mutex& mutex)
:
  mutex_  (mutex),
  locked_ (true)
{
  mutex_.lock();
}

inline
Mutex::Lock::Lock(Mutex& mutex, NotLock)
:
  mutex_  (mutex),
  locked_ (false)
{}

inline
Mutex::Lock::Lock(Mutex& mutex, TryLock)
:
  mutex_  (mutex),
  locked_ (mutex.trylock())
{}

inline
Mutex::Lock::~Lock()
{
  if(locked_)
    mutex_.unlock();
}

inline
void Mutex::Lock::acquire()
{
  mutex_.lock();
  locked_ = true;
}

inline
bool Mutex::Lock::try_acquire()
{
  locked_ = mutex_.trylock();
  return locked_;
}

inline
void Mutex::Lock::release()
{
  mutex_.unlock();
  locked_ = false;
}

inline
bool Mutex::Lock::locked() const
{
  return locked_;
}


/**** Glib::RecMutex::Lock *************************************************/

inline
RecMutex::Lock::Lock(RecMutex& mutex)
:
  mutex_  (mutex),
  locked_ (true)
{
  mutex_.lock();
}

inline
RecMutex::Lock::Lock(RecMutex& mutex, NotLock)
:
  mutex_  (mutex),
  locked_ (false)
{}

inline
RecMutex::Lock::Lock(RecMutex& mutex, TryLock)
:
  mutex_  (mutex),
  locked_ (mutex.trylock())
{}

inline
RecMutex::Lock::~Lock()
{
  if(locked_)
    mutex_.unlock();
}

inline
void RecMutex::Lock::acquire()
{
  mutex_.lock();
  locked_ = true;
}

inline
bool RecMutex::Lock::try_acquire()
{
  locked_ = mutex_.trylock();
  return locked_;
}

inline
void RecMutex::Lock::release()
{
  mutex_.unlock();
  locked_ = false;
}

inline
bool RecMutex::Lock::locked() const
{
  return locked_;
}


/**** Glib::RWLock::ReaderLock *********************************************/

inline
RWLock::ReaderLock::ReaderLock(RWLock& rwlock)
:
  rwlock_ (rwlock),
  locked_ (true)
{
  rwlock_.reader_lock();
}

inline
RWLock::ReaderLock::ReaderLock(RWLock& rwlock, NotLock)
:
  rwlock_ (rwlock),
  locked_ (false)
{}

inline
RWLock::ReaderLock::ReaderLock(RWLock& rwlock, TryLock)
:
  rwlock_ (rwlock),
  locked_ (rwlock.reader_trylock())
{}

inline
RWLock::ReaderLock::~ReaderLock()
{
  if(locked_)
    rwlock_.reader_unlock();
}

inline
void RWLock::ReaderLock::acquire()
{
  rwlock_.reader_lock();
  locked_ = true;
}

inline
bool RWLock::ReaderLock::try_acquire()
{
  locked_ = rwlock_.reader_trylock();
  return locked_;
}

inline
void RWLock::ReaderLock::release()
{
  rwlock_.reader_unlock();
  locked_ = false;
}

inline
bool RWLock::ReaderLock::locked() const
{
  return locked_;
}


/**** Glib::RWLock::WriterLock *********************************************/

inline
RWLock::WriterLock::WriterLock(RWLock& rwlock)
:
  rwlock_ (rwlock),
  locked_ (true)
{
  rwlock_.writer_lock();
}

inline
RWLock::WriterLock::WriterLock(RWLock& rwlock, NotLock)
:
  rwlock_ (rwlock),
  locked_ (false)
{}

inline
RWLock::WriterLock::WriterLock(RWLock& rwlock, TryLock)
:
  rwlock_ (rwlock),
  locked_ (rwlock.writer_trylock())
{}

inline
RWLock::WriterLock::~WriterLock()
{
  if(locked_)
    rwlock_.writer_unlock();
}

inline
void RWLock::WriterLock::acquire()
{
  rwlock_.writer_lock();
  locked_ = true;
}

inline
bool RWLock::WriterLock::try_acquire()
{
  locked_ = rwlock_.writer_trylock();
  return locked_;
}

inline
void RWLock::WriterLock::release()
{
  rwlock_.writer_unlock();
  locked_ = false;
}

inline
bool RWLock::WriterLock::locked() const
{
  return locked_;
}


/**** Glib::StaticPrivate **************************************************/

// static
template <class T>
void StaticPrivate<T>::delete_ptr(void* data)
{
  delete static_cast<T*>(data);
}

template <class T> inline
T* StaticPrivate<T>::get()
{
  return static_cast<T*>(g_static_private_get(&gobject_));
}

template <class T> inline
void StaticPrivate<T>::set(T* data, typename StaticPrivate<T>::DestroyNotifyFunc notify_func)
{
  g_static_private_set(&gobject_, data, notify_func);
}


/**** Glib::Private ********************************************************/

// static
template <class T>
void Private<T>::delete_ptr(void* data)
{
  delete static_cast<T*>(data);
}

template <class T> inline
Private<T>::Private(typename Private<T>::DestructorFunc destructor_func)
:
  gobject_ (g_private_new(destructor_func))
{}

template <class T> inline
T* Private<T>::get()
{
  return static_cast<T*>(g_private_get(gobject_));
}

template <class T> inline
void Private<T>::set(T* data)
{
  g_private_set(gobject_, data);
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GLIBMM_THREAD_H */

