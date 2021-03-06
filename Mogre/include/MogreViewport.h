#pragma once

#include "OgreViewport.h"
#include "Marshalling.h"

namespace Mogre
{
	ref class RenderTarget;

	public ref class Viewport : IMogreDisposable
	{
	public:
		/// <summary>Raised before any disposing is performed.</summary>
		virtual event EventHandler^ OnDisposing;
		/// <summary>Raised once all disposing is performed.</summary>
		virtual event EventHandler^ OnDisposed;

	internal:
		Ogre::Viewport* _native;
		bool _createdByCLR;

	public protected:
		Viewport(Ogre::Viewport* obj) : _native(obj)
		{
		}

	public:
		~Viewport();
	protected:
		!Viewport();

	public:
		property int ActualHeight
		{
		public:
			int get();
		}

		property int ActualLeft
		{
		public:
			int get();
		}

		property int ActualTop
		{
		public:
			int get();
		}

		property int ActualWidth
		{
		public:
			int get();
		}

		property Ogre::Real Height
		{
		public:
			Ogre::Real get();
		}

		property Ogre::Real Left
		{
		public:
			Ogre::Real get();
		}

		property String^ MaterialScheme
		{
		public:
			String^ get();
		public:
			void set(String^ schemeName);
		}

		property bool OverlaysEnabled
		{
		public:
			bool get();
		public:
			void set(bool enabled);
		}

		property String^ RenderQueueInvocationSequenceName
		{
		public:
			String^ get();
		public:
			void set(String^ sequenceName);
		}

		property bool SkiesEnabled
		{
		public:
			bool get();
		public:
			void set(bool enabled);
		}

		property Ogre::Real Top
		{
		public:
			Ogre::Real get();
		}

		property Ogre::uint VisibilityMask
		{
		public:
			Ogre::uint get();
		}

		property Ogre::Real Width
		{
		public:
			Ogre::Real get();
		}

		property Mogre::RenderTarget^ Target
		{
		public:
			Mogre::RenderTarget^ get();
		}

		property bool IsDisposed
		{
			virtual bool get()
			{
				return _native == nullptr;
			}
		}

		void _updateDimensions();
		void SetDimensions(Ogre::Real left, Ogre::Real top, Ogre::Real width, Ogre::Real height);
		void GetActualDimensions([Out] int% left, [Out] int% top, [Out] int% width, [Out] int% height);

		void Clear();
		void Clear(unsigned int buffers);
		void Clear(unsigned int buffers, Mogre::ColourValue colour);
		void Clear(unsigned int buffers, Mogre::ColourValue colour, Ogre::Real depth);
		void Clear(unsigned int buffers, Mogre::ColourValue colour, Ogre::Real depth, unsigned short stencil);

		virtual bool Equals(Object^ obj) override
		{
			Viewport^ clr = dynamic_cast<Viewport^>(obj);
			if (clr == CLR_NULL)
			{
				return false;
			}

			return (_native == clr->_native);
		}

		bool Equals(Viewport^ obj)
		{
			if (obj == CLR_NULL)
			{
				return false;
			}

			return (_native == obj->_native);
		}

		virtual int GetHashCode() override
		{
			return reinterpret_cast<int>(_native);
		}

		property IntPtr NativePtr
		{
			IntPtr get() { return (IntPtr)_native; }
		}

		DEFINE_MANAGED_NATIVE_CONVERSIONS(Viewport);
	};
}