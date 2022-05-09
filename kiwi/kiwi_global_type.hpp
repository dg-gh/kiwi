#ifndef KIWI_GLOBAL_TYPE_HPP
#define KIWI_GLOBAL_TYPE_HPP


////// INCLUDES //////

#include <utility>
#include <memory>


////// DESCRIPTIONS //////

namespace kiwi
{
	template <class base_type, unsigned int id_number = static_cast<unsigned int>(-1), class _Allocator = std::allocator<base_type>> class _global_instance;
	template <class base_type, unsigned int id_number, class _Allocator> class _global_pointer;

	template <class base_type, unsigned int id_number = static_cast<unsigned int>(-1), class _Allocator = std::allocator<base_type>>
	using global_type = kiwi::_global_instance<base_type, id_number, _Allocator>&;

	template <class base_type, unsigned int id_number = static_cast<unsigned int>(-1), class _Allocator = std::allocator<base_type>, class ... _Args>
	inline _global_instance<base_type, id_number, _Allocator>& make_global_type(_Args&& ... args);

	template <class base_type, unsigned int id_number = static_cast<unsigned int>(-1), class _Allocator = std::allocator<base_type>>
	inline _global_instance<base_type, id_number, _Allocator>& get_global_type() noexcept;

	template <class base_type, unsigned int id_number = static_cast<unsigned int>(-1), class _Allocator = std::allocator<base_type>>
	inline void delete_global_type() noexcept;

	template <class base_type, unsigned int id_number = static_cast<unsigned int>(-1), class _Allocator = std::allocator<base_type>>
	inline bool is_global_type_created() noexcept;

	template <class base_type, unsigned int id_number, class _Allocator> class _global_instance : public base_type
	{

	public:

		base_type& operator=(const base_type& rhs_base_object);
		base_type& operator=(base_type&& rhs_base_object) noexcept;

		inline const base_type* base_type_ptr() const noexcept;
		inline base_type* base_type_ptr() noexcept;
		inline const base_type& base_type_ref() const noexcept;
		inline base_type& base_type_ref() noexcept;

		constexpr unsigned int global_type_id() const noexcept;

	private:

		static _global_pointer<base_type, id_number, _Allocator> _global_instance_ptr;

		_global_instance() = delete;
		_global_instance(const _global_instance<base_type, id_number, _Allocator>&) = delete;
		kiwi::_global_instance<base_type, id_number, _Allocator>& operator=(const kiwi::_global_instance<base_type, id_number, _Allocator>&) = delete;
		_global_instance(_global_instance<base_type, id_number, _Allocator>&&) = delete;
		kiwi::_global_instance<base_type, id_number, _Allocator>& operator=(kiwi::_global_instance<base_type, id_number, _Allocator>&&) = delete;
		~_global_instance() = default;

	public:

		template <class base_type2, unsigned int id_number2, class _Allocator2, class ... _Args>
		friend inline _global_instance<base_type2, id_number2, _Allocator2>& make_global_type(_Args&& ... args);

		template <class base_type2, unsigned int id_number2, class _Allocator2>
		friend inline _global_instance<base_type2, id_number2, _Allocator2>& get_global_type() noexcept;

		template <class base_type2, unsigned int id_number2, class _Allocator2>
		friend inline void delete_global_type() noexcept;

		template <class base_type2, unsigned int id_number2, class _Allocator2> friend inline bool is_global_type_created() noexcept;
	};

	template <class base_type, unsigned int id_number, class _Allocator> class _global_pointer : public _Allocator
	{

	public:

		template <class base_type2, unsigned int id_number2, class _Allocator2>
		friend class _global_instance;

		template <class base_type2, unsigned int id_number2, class _Allocator2, class ... _Args>
		friend inline _global_instance<base_type2, id_number2, _Allocator2>& make_global_type(_Args&& ... args);

		template <class base_type2, unsigned int id_number2, class _Allocator2>
		friend inline _global_instance<base_type2, id_number2, _Allocator2>& get_global_type() noexcept;

		template <class base_type2, unsigned int id_number2, class _Allocator2>
		friend inline void delete_global_type() noexcept;

		template <class base_type2, unsigned int id_number2, class _Allocator2> friend inline bool is_global_type_created() noexcept;

	private:

		base_type* m_raw_ptr = nullptr;

		_global_pointer(base_type* const rhs_ptr);

		_global_pointer() = delete;
		_global_pointer(const _global_pointer<base_type, id_number, _Allocator>&) = default;
		_global_pointer<base_type, id_number, _Allocator> operator=(const _global_pointer<base_type, id_number, _Allocator>&) = delete;
		_global_pointer(_global_pointer<base_type, id_number, _Allocator>&&) = default;
		_global_pointer<base_type, id_number, _Allocator> operator=(_global_pointer<base_type, id_number, _Allocator>&&) = delete;
		~_global_pointer();
	};
}


////// IMPLEMENTATIONS //////

template <class base_type, unsigned int id_number, class _Allocator>
kiwi::_global_pointer<base_type, id_number, _Allocator> kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr = nullptr;

template <class base_type, unsigned int id_number, class _Allocator, class ... _Args>
inline kiwi::_global_instance<base_type, id_number, _Allocator>& kiwi::make_global_type(_Args&& ... args)
{
	if (kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr != nullptr)
	{
		return *static_cast<kiwi::_global_instance<base_type, id_number, _Allocator>*>(static_cast<void*>(
			kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr));
	}
	else
	{
		try
		{
			kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr
				= static_cast<_global_instance<base_type, id_number, _Allocator>*>(static_cast<void*>(
					kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.allocate(1)));

			if (kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr != nullptr)
			{
				new (kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr)
					base_type(std::forward<_Args>(args)...);
			}
		}
		catch (...)
		{
			if (kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr != nullptr)
			{
				kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.deallocate(
					kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr, 1);
				kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr = nullptr;
			}
		}

		return *static_cast<kiwi::_global_instance<base_type, id_number, _Allocator>*>(static_cast<void*>(
			kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr));
	}
}

template <class base_type, unsigned int id_number, class _Allocator>
inline kiwi::_global_instance<base_type, id_number, _Allocator>& kiwi::get_global_type() noexcept
{
	return *static_cast<kiwi::_global_instance<base_type, id_number, _Allocator>*>(static_cast<void*>(
		kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr));
}

template <class base_type, unsigned int id_number, class _Allocator>
inline void kiwi::delete_global_type() noexcept
{
	if (kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr != nullptr)
	{
		kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr->~base_type();
		kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.deallocate(
			kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr, 1);
		kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr = nullptr;
	}
}

template <class base_type, unsigned int id_number, class _Allocator>
inline bool kiwi::is_global_type_created() noexcept
{
	return kiwi::_global_instance<base_type, id_number, _Allocator>::_global_instance_ptr.m_raw_ptr != nullptr;
}

template <class base_type, unsigned int id_number, class _Allocator>
base_type& kiwi::_global_instance<base_type, id_number, _Allocator>::operator=(const base_type& rhs_base_object)
{
	*_global_instance_ptr.m_raw_ptr = rhs_base_object;
	return *_global_instance_ptr.m_raw_ptr;
}

template <class base_type, unsigned int id_number, class _Allocator>
base_type& kiwi::_global_instance<base_type, id_number, _Allocator>::operator=(base_type&& rhs_base_object) noexcept
{
	*_global_instance_ptr.m_raw_ptr = std::move(rhs_base_object);
	return *_global_instance_ptr.m_raw_ptr;
}

template <class base_type, unsigned int id_number, class _Allocator>
inline const base_type* kiwi::_global_instance<base_type, id_number, _Allocator>::base_type_ptr() const noexcept
{
	return _global_instance_ptr.m_raw_ptr;
}

template <class base_type, unsigned int id_number, class _Allocator>
inline base_type* kiwi::_global_instance<base_type, id_number, _Allocator>::base_type_ptr() noexcept
{
	return _global_instance_ptr.m_raw_ptr;
}

template <class base_type, unsigned int id_number, class _Allocator>
inline const base_type& kiwi::_global_instance<base_type, id_number, _Allocator>::base_type_ref() const noexcept
{
	return *_global_instance_ptr.m_raw_ptr;
}

template <class base_type, unsigned int id_number, class _Allocator>
inline base_type& kiwi::_global_instance<base_type, id_number, _Allocator>::base_type_ref() noexcept
{
	return *_global_instance_ptr.m_raw_ptr;
}

template <class base_type, unsigned int id_number, class _Allocator>
constexpr unsigned int kiwi::_global_instance<base_type, id_number, _Allocator>::global_type_id() const noexcept
{
	return id_number;
}

template <class base_type, unsigned int id_number, class _Allocator>
kiwi::_global_pointer<base_type, id_number, _Allocator>::_global_pointer(base_type* rhs_ptr)
{
	m_raw_ptr = rhs_ptr;
}

template <class base_type, unsigned int id_number, class _Allocator>
kiwi::_global_pointer<base_type, id_number, _Allocator>::~_global_pointer()
{
	if (m_raw_ptr != nullptr)
	{
		m_raw_ptr->~base_type();
		this->deallocate(m_raw_ptr, sizeof(base_type));
	}
}


#endif // KIWI_GLOBAL_TYPE_HPP