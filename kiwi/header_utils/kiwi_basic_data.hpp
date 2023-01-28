#ifndef _KIWI_BASIC_DATA_HPP
#define _KIWI_BASIC_DATA_HPP

#include "header_utils/kiwi_glcall.hpp"
#include <cstddef>


namespace kiwi
{
	class RGBA
	{

	public:

		inline RGBA(GLfloat R, GLfloat G, GLfloat B) noexcept;
		inline RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept;

		RGBA() noexcept = default;
		RGBA(const kiwi::RGBA&) noexcept = default;
		kiwi::RGBA& operator=(const kiwi::RGBA&) noexcept = default;
		RGBA(kiwi::RGBA&&) noexcept = default;
		kiwi::RGBA& operator=(kiwi::RGBA&&) noexcept = default;
		~RGBA() = default;

		static inline const kiwi::RGBA& ref(const GLfloat* const ptr) noexcept;

		inline GLfloat& operator[](std::size_t offset) noexcept;
		inline const GLfloat& operator[](std::size_t offset) const noexcept;

		inline GLfloat& R() noexcept;
		inline const GLfloat& R() const noexcept;
		inline GLfloat& G() noexcept;
		inline const GLfloat& G() const noexcept;
		inline GLfloat& B() noexcept;
		inline const GLfloat& B() const noexcept;
		inline GLfloat& A() noexcept;
		inline const GLfloat& A() const noexcept;

		inline GLfloat* data() noexcept;
		inline const GLfloat* data() const noexcept;

	private:

		GLfloat m_RGBA[4] = { static_cast<GLfloat>(0) };
	};

	class size
	{

	public:

		inline size(std::size_t X, std::size_t Y) noexcept;

		size() noexcept = default;
		size(const kiwi::size&) noexcept = default;
		kiwi::size& operator=(const kiwi::size&) noexcept = default;
		size(kiwi::size&&) noexcept = default;
		kiwi::size& operator=(kiwi::size&&) noexcept = default;
		~size() = default;

		static inline const kiwi::size& ref(const std::size_t* const ptr) noexcept;

		inline std::size_t& operator[](std::size_t offset) noexcept;
		inline const std::size_t& operator[](std::size_t offset) const noexcept;

		inline std::size_t& X() noexcept;
		inline const std::size_t& X() const noexcept;
		inline std::size_t& Y() noexcept;
		inline const std::size_t& Y() const noexcept;

		inline std::size_t* data() noexcept;
		inline const std::size_t* data() const noexcept;

	private:

		std::size_t m_resolution[2] = { 0, 0 };
	};

	class XYZ;

	class XY
	{

	public:

		friend class XYZ;

		inline XY(GLfloat X, GLfloat Y) noexcept;
		inline XY(kiwi::XYZ _XYZ) noexcept;

		XY() noexcept = default;
		XY(const kiwi::XY&) noexcept = default;
		kiwi::XY& operator=(const kiwi::XY&) noexcept = default;
		XY(kiwi::XY&&) noexcept = default;
		kiwi::XY& operator=(kiwi::XY&&) noexcept = default;
		~XY() noexcept = default;

		static inline const kiwi::XY& ref(const GLfloat* const ptr) noexcept;

		inline GLfloat& operator[](std::size_t offset) noexcept;
		inline const GLfloat& operator[](std::size_t offset) const noexcept;

		inline GLfloat& X() noexcept;
		inline const GLfloat& X() const noexcept;
		inline GLfloat& Y() noexcept;
		inline const GLfloat& Y() const noexcept;

		inline GLfloat* data() noexcept;
		inline const GLfloat* data() const noexcept;

	private:

		GLfloat m_XY[2] = { static_cast<GLfloat>(0), static_cast<GLfloat>(0) };
	};

	class XYZ
	{

	public:

		friend class XY;

		inline XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept;
		inline XYZ(kiwi::XY _XY) noexcept;
		inline XYZ(kiwi::XY _XY, GLfloat Z) noexcept;

		XYZ() noexcept = default;
		XYZ(const kiwi::XYZ&) noexcept = default;
		kiwi::XYZ& operator=(const kiwi::XYZ&) noexcept = default;
		XYZ(kiwi::XYZ&&) noexcept = default;
		kiwi::XYZ& operator=(kiwi::XYZ&&) noexcept = default;
		~XYZ() = default;

		static inline const kiwi::XYZ& ref(const GLfloat* const ptr) noexcept;

		inline GLfloat& operator[](std::size_t offset) noexcept;
		inline const GLfloat& operator[](std::size_t offset) const noexcept;

		inline GLfloat& X() noexcept;
		inline const GLfloat& X() const noexcept;
		inline GLfloat& Y() noexcept;
		inline const GLfloat& Y() const noexcept;
		inline GLfloat& Z() noexcept;
		inline const GLfloat& Z() const noexcept;

		inline GLfloat* data() noexcept;
		inline const GLfloat* data() const noexcept;

	private:

		GLfloat m_XYZ[3] = { static_cast<GLfloat>(0), static_cast<GLfloat>(0), static_cast<GLfloat>(0) };
	};

	class UV
	{

	public:

		inline UV(GLfloat U, GLfloat V) noexcept;

		UV() = default;
		UV(const kiwi::UV&) noexcept = default;
		kiwi::UV& operator=(const kiwi::UV&) noexcept = default;
		UV(kiwi::UV&&) noexcept = default;
		kiwi::UV& operator=(kiwi::UV&&) noexcept = default;
		~UV() = default;

		static inline const kiwi::UV& ref(const GLfloat* const ptr) noexcept;

		inline GLfloat& operator[](std::size_t offset) noexcept;
		inline const GLfloat& operator[](std::size_t offset) const noexcept;

		inline GLfloat& U() noexcept;
		inline const GLfloat& U() const noexcept;
		inline GLfloat& V() noexcept;
		inline const GLfloat& V() const noexcept;

		inline GLfloat* data() noexcept;
		inline const GLfloat* data() const noexcept;

	private:

		GLfloat m_UV[2] = { static_cast<GLfloat>(0), static_cast<GLfloat>(0) };
	};

	class RMEC
	{

	public:

		inline RMEC(GLfloat roughness) noexcept;
		inline RMEC(GLfloat roughness, GLfloat metalness) noexcept;
		inline RMEC(GLfloat roughness, GLfloat metalness, GLfloat emissivity) noexcept;
		inline RMEC(GLfloat roughness, GLfloat metalness, GLfloat emissivity, GLfloat ceiling) noexcept;

		RMEC() noexcept = default;
		RMEC(const kiwi::RMEC&) noexcept = default;
		kiwi::RMEC& operator=(const kiwi::RMEC&) noexcept = default;
		RMEC(kiwi::RMEC&&) noexcept = default;
		kiwi::RMEC& operator=(kiwi::RMEC&&) noexcept = default;
		~RMEC() = default;

		static inline const kiwi::RMEC& ref(const GLfloat* const ptr) noexcept;

		inline GLfloat& operator[](std::size_t offset) noexcept;
		inline const GLfloat& operator[](std::size_t offset) const noexcept;

		inline GLfloat& R() noexcept;
		inline const GLfloat& R() const noexcept;
		inline GLfloat& M() noexcept;
		inline const GLfloat& M() const noexcept;
		inline GLfloat& E() noexcept;
		inline const GLfloat& E() const noexcept;
		inline GLfloat& C() noexcept;
		inline const GLfloat& C() const noexcept;

		inline GLfloat* data() noexcept;
		inline const GLfloat* data() const noexcept;

	private:

		GLfloat m_RMEC[4] = { static_cast<GLfloat>(1), static_cast<GLfloat>(0), static_cast<GLfloat>(0), static_cast<GLfloat>(1) };
	};

	class ECx
	{

	public:

		inline ECx(GLfloat emissivity_factor) noexcept;
		inline ECx(GLfloat emissivity_factor, GLfloat ceiling_factor) noexcept;

		ECx() noexcept = default;
		ECx(const kiwi::ECx&) noexcept = default;
		kiwi::ECx& operator=(const kiwi::ECx&) noexcept = default;
		ECx(kiwi::ECx&&) noexcept = default;
		kiwi::ECx& operator=(kiwi::ECx&&) noexcept = default;
		~ECx() = default;

		static inline const kiwi::ECx& ref(const GLfloat* const ptr) noexcept;

		inline GLfloat& operator[](std::size_t offset) noexcept;
		inline const GLfloat& operator[](std::size_t offset) const noexcept;

		inline GLfloat& Ex() noexcept;
		inline const GLfloat& Ex() const noexcept;
		inline GLfloat& Cx() noexcept;
		inline const GLfloat& Cx() const noexcept;

		inline GLfloat* data() noexcept;
		inline const GLfloat* data() const noexcept;

	private:

		GLfloat m_ECx[2] = { static_cast<GLfloat>(1), static_cast<GLfloat>(1) };
	};

	class NF
	{

	public:

		inline NF(GLfloat near, GLfloat far) noexcept;

		NF() = default;
		NF(const kiwi::NF&) noexcept = default;
		kiwi::NF& operator=(const kiwi::NF&) noexcept = default;
		NF(kiwi::NF&&) noexcept = default;
		kiwi::NF& operator=(kiwi::NF&&) noexcept = default;
		~NF() = default;

		static inline const kiwi::NF& ref(const GLfloat* const ptr) noexcept;

		inline GLfloat& operator[](std::size_t offset) noexcept;
		inline const GLfloat& operator[](std::size_t offset) const noexcept;

		inline GLfloat& N() noexcept;
		inline const GLfloat& N() const noexcept;
		inline GLfloat& F() noexcept;
		inline const GLfloat& F() const noexcept;

		inline GLfloat* data() noexcept;
		inline const GLfloat* data() const noexcept;

	private:

		GLfloat m_NF[2] = { static_cast<GLfloat>(0), static_cast<GLfloat>(0) };
	};
}


// INLINE IMPLEMENTATION

inline kiwi::RGBA::RGBA(GLfloat R, GLfloat G, GLfloat B) noexcept : m_RGBA{ R, G, B, 1.0f } {}
inline kiwi::RGBA::RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept : m_RGBA{ R, G, B, A } {}
inline const kiwi::RGBA& kiwi::RGBA::ref(const GLfloat* const ptr) noexcept { return reinterpret_cast<const kiwi::RGBA&>(*ptr); }
inline GLfloat& kiwi::RGBA::operator[](std::size_t offset) noexcept { return m_RGBA[offset]; }
inline const GLfloat& kiwi::RGBA::operator[](std::size_t offset) const noexcept { return m_RGBA[offset]; }
inline GLfloat& kiwi::RGBA::R() noexcept { return m_RGBA[0]; }
inline const GLfloat& kiwi::RGBA::R() const noexcept { return m_RGBA[0]; }
inline GLfloat& kiwi::RGBA::G() noexcept { return m_RGBA[1]; }
inline const GLfloat& kiwi::RGBA::G() const noexcept { return m_RGBA[1]; }
inline GLfloat& kiwi::RGBA::B() noexcept { return m_RGBA[2]; }
inline const GLfloat& kiwi::RGBA::B() const noexcept { return m_RGBA[2]; }
inline GLfloat& kiwi::RGBA::A() noexcept { return m_RGBA[3]; }
inline const GLfloat& kiwi::RGBA::A() const noexcept { return m_RGBA[3]; }
inline GLfloat* kiwi::RGBA::data() noexcept { return static_cast<GLfloat*>(m_RGBA); }
inline const GLfloat* kiwi::RGBA::data() const noexcept { return static_cast<const GLfloat*>(m_RGBA); }


inline kiwi::size::size(std::size_t X, std::size_t Y) noexcept : m_resolution{ X, Y } {}
inline const kiwi::size& kiwi::size::ref(const std::size_t* const ptr) noexcept { return reinterpret_cast<const kiwi::size&>(*ptr); }
inline std::size_t& kiwi::size::operator[](std::size_t offset) noexcept { return m_resolution[offset]; }
inline const std::size_t& kiwi::size::operator[](std::size_t offset) const noexcept { return m_resolution[offset]; }
inline std::size_t& kiwi::size::X() noexcept { return m_resolution[0]; }
inline const std::size_t& kiwi::size::X() const noexcept { return m_resolution[0]; }
inline std::size_t& kiwi::size::Y() noexcept { return m_resolution[1]; }
inline const std::size_t& kiwi::size::Y() const noexcept { return m_resolution[1]; }
inline std::size_t* kiwi::size::data() noexcept { return static_cast<std::size_t*>(m_resolution); }
inline const std::size_t* kiwi::size::data() const noexcept { return static_cast<const std::size_t*>(m_resolution); }


inline kiwi::XY::XY(GLfloat X, GLfloat Y) noexcept : m_XY{ X, Y } {}
inline kiwi::XY::XY(kiwi::XYZ _XYZ) noexcept : m_XY{ _XYZ.m_XYZ[0], _XYZ.m_XYZ[1] } {}
inline const kiwi::XY& kiwi::XY::ref(const GLfloat* const ptr) noexcept { return reinterpret_cast<const kiwi::XY&>(*ptr); }
inline GLfloat& kiwi::XY::operator[](std::size_t offset) noexcept { return m_XY[offset]; }
inline const GLfloat& kiwi::XY::operator[](std::size_t offset) const noexcept { return m_XY[offset]; }
inline GLfloat& kiwi::XY::X() noexcept { return m_XY[0]; }
inline const GLfloat& kiwi::XY::X() const noexcept { return m_XY[0]; }
inline GLfloat& kiwi::XY::Y() noexcept { return m_XY[1]; }
inline const GLfloat& kiwi::XY::Y() const noexcept { return m_XY[1]; }
inline GLfloat* kiwi::XY::data() noexcept { return static_cast<GLfloat*>(m_XY); }
inline const GLfloat* kiwi::XY::data() const noexcept { return static_cast<const GLfloat*>(m_XY); }


inline kiwi::XYZ::XYZ(GLfloat X, GLfloat Y, GLfloat Z) noexcept : m_XYZ{ X, Y, Z } {}
inline kiwi::XYZ::XYZ(kiwi::XY _XY) noexcept : m_XYZ{ _XY.m_XY[0], _XY.m_XY[1], static_cast<GLfloat>(0) } {}
inline kiwi::XYZ::XYZ(kiwi::XY _XY, GLfloat Z) noexcept : m_XYZ{ _XY.m_XY[0], _XY.m_XY[1], Z } {}
inline const kiwi::XYZ& kiwi::XYZ::ref(const GLfloat* const ptr) noexcept { return reinterpret_cast<const kiwi::XYZ&>(*ptr); }
inline GLfloat& kiwi::XYZ::operator[](std::size_t offset) noexcept { return m_XYZ[offset]; }
inline const GLfloat& kiwi::XYZ::operator[](std::size_t offset) const noexcept { return m_XYZ[offset]; }
inline GLfloat& kiwi::XYZ::X() noexcept { return m_XYZ[0]; }
inline const GLfloat& kiwi::XYZ::X() const noexcept { return m_XYZ[0]; }
inline GLfloat& kiwi::XYZ::Y() noexcept { return m_XYZ[1]; }
inline const GLfloat& kiwi::XYZ::Y() const noexcept { return m_XYZ[1]; }
inline GLfloat& kiwi::XYZ::Z() noexcept { return m_XYZ[2]; }
inline const GLfloat& kiwi::XYZ::Z() const noexcept { return m_XYZ[2]; }
inline GLfloat* kiwi::XYZ::data() noexcept { return static_cast<GLfloat*>(m_XYZ); }
inline const GLfloat* kiwi::XYZ::data() const noexcept { return static_cast<const GLfloat*>(m_XYZ); }


inline kiwi::UV::UV(GLfloat U, GLfloat V) noexcept : m_UV{ U, V } {}
inline const kiwi::UV& kiwi::UV::ref(const GLfloat* const ptr) noexcept { return reinterpret_cast<const kiwi::UV&>(*ptr); }
inline GLfloat& kiwi::UV::operator[](std::size_t offset) noexcept { return m_UV[offset]; }
inline const GLfloat& kiwi::UV::operator[](std::size_t offset) const noexcept { return m_UV[offset]; }
inline GLfloat& kiwi::UV::U() noexcept { return m_UV[0]; }
inline const GLfloat& kiwi::UV::U() const noexcept { return m_UV[0]; }
inline GLfloat& kiwi::UV::V() noexcept { return m_UV[1]; }
inline const GLfloat& kiwi::UV::V() const noexcept { return m_UV[1]; }
inline GLfloat* kiwi::UV::data() noexcept { return static_cast<GLfloat*>(m_UV); }
inline const GLfloat* kiwi::UV::data() const noexcept { return static_cast<const GLfloat*>(m_UV); }


inline kiwi::RMEC::RMEC(GLfloat roughness) noexcept : m_RMEC{ roughness, static_cast<GLfloat>(0), static_cast<GLfloat>(0), static_cast<GLfloat>(1) } {}
inline kiwi::RMEC::RMEC(GLfloat roughness, GLfloat metalness) noexcept : m_RMEC{ roughness, metalness, static_cast<GLfloat>(0), static_cast<GLfloat>(1) } {}
inline kiwi::RMEC::RMEC(GLfloat roughness, GLfloat metalness, GLfloat emissivity) noexcept : m_RMEC{ roughness, metalness, emissivity, static_cast<GLfloat>(1) } {}
inline kiwi::RMEC::RMEC(GLfloat roughness, GLfloat metalness, GLfloat emissivity, GLfloat ceiling) noexcept : m_RMEC{ roughness, metalness, emissivity, ceiling } {}
inline const kiwi::RMEC& kiwi::RMEC::ref(const GLfloat* const ptr) noexcept { return reinterpret_cast<const kiwi::RMEC&>(*ptr); }
inline GLfloat& kiwi::RMEC::operator[](std::size_t offset) noexcept { return m_RMEC[offset]; }
inline const GLfloat& kiwi::RMEC::operator[](std::size_t offset) const noexcept { return m_RMEC[offset]; }
inline GLfloat& kiwi::RMEC::R() noexcept { return m_RMEC[0]; }
inline const GLfloat& kiwi::RMEC::R() const noexcept { return m_RMEC[0]; }
inline GLfloat& kiwi::RMEC::M() noexcept { return m_RMEC[1]; }
inline const GLfloat& kiwi::RMEC::M() const noexcept { return m_RMEC[1]; }
inline GLfloat& kiwi::RMEC::E() noexcept { return m_RMEC[2]; }
inline const GLfloat& kiwi::RMEC::E() const noexcept { return m_RMEC[2]; }
inline GLfloat& kiwi::RMEC::C() noexcept { return m_RMEC[3]; }
inline const GLfloat& kiwi::RMEC::C() const noexcept { return m_RMEC[3]; }
inline GLfloat* kiwi::RMEC::data() noexcept { return static_cast<GLfloat*>(m_RMEC); }
inline const GLfloat* kiwi::RMEC::data() const noexcept { return static_cast<const GLfloat*>(m_RMEC); }


inline kiwi::ECx::ECx(GLfloat emissivity_factor) noexcept : m_ECx{ emissivity_factor, static_cast<GLfloat>(1) } {}
inline kiwi::ECx::ECx(GLfloat emissivity_factor, GLfloat ceiling_factor) noexcept : m_ECx{ emissivity_factor, ceiling_factor } {}
inline const kiwi::ECx& kiwi::ECx::ref(const GLfloat* const ptr) noexcept { return reinterpret_cast<const kiwi::ECx&>(*ptr); }
inline GLfloat& kiwi::ECx::operator[](std::size_t offset) noexcept { return m_ECx[offset]; }
inline const GLfloat& kiwi::ECx::operator[](std::size_t offset) const noexcept { return m_ECx[offset]; }
inline GLfloat& kiwi::ECx::Ex() noexcept { return m_ECx[0]; }
inline const GLfloat& kiwi::ECx::Ex() const noexcept { return m_ECx[0]; }
inline GLfloat& kiwi::ECx::Cx() noexcept { return m_ECx[1]; }
inline const GLfloat& kiwi::ECx::Cx() const noexcept { return m_ECx[1]; }
inline GLfloat* kiwi::ECx::data() noexcept { return static_cast<GLfloat*>(m_ECx); }
inline const GLfloat* kiwi::ECx::data() const noexcept { return static_cast<const GLfloat*>(m_ECx); }

inline kiwi::NF::NF(GLfloat near, GLfloat far) noexcept : m_NF{ near, far } {}
inline const kiwi::NF& kiwi::NF::ref(const GLfloat* const ptr) noexcept { return reinterpret_cast<const kiwi::NF&>(*ptr); }
inline GLfloat& kiwi::NF::operator[](std::size_t offset) noexcept { return m_NF[offset]; }
inline const GLfloat& kiwi::NF::operator[](std::size_t offset) const noexcept { return m_NF[offset]; }
inline GLfloat& kiwi::NF::N() noexcept { return m_NF[0]; }
inline const GLfloat& kiwi::NF::N() const noexcept { return m_NF[0]; }
inline GLfloat& kiwi::NF::F() noexcept { return m_NF[1]; }
inline const GLfloat& kiwi::NF::F() const noexcept { return m_NF[1]; }
inline GLfloat* kiwi::NF::data() noexcept { return static_cast<GLfloat*>(m_NF); }
inline const GLfloat* kiwi::NF::data() const noexcept { return static_cast<const GLfloat*>(m_NF); }

#endif // _KIWI_BASIC_DATA_HPP