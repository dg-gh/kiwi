#ifndef _KIWI_BASIC_DATA_HPP
#define _KIWI_BASIC_DATA_HPP

#include "kiwi_includes.hpp"


namespace kiwi
{
	class RGBA
	{

	public:

		inline RGBA(GLfloat R, GLfloat G, GLfloat B) noexcept;
		inline RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept;

		RGBA() = default;
		RGBA(const kiwi::RGBA&) = default;
		kiwi::RGBA& operator=(const kiwi::RGBA&) = default;
		RGBA(kiwi::RGBA&&) = default;
		kiwi::RGBA& operator=(kiwi::RGBA&&) = default;
		~RGBA() = default;

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

		size() = default;
		size(const kiwi::size&) = default;
		kiwi::size& operator=(const kiwi::size&) = default;
		size(kiwi::size&&) = default;
		kiwi::size& operator=(kiwi::size&&) = default;
		~size() = default;

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

		XY() = default;
		XY(const kiwi::XY&) = default;
		kiwi::XY& operator=(const kiwi::XY&) = default;
		XY(kiwi::XY&&) = default;
		kiwi::XY& operator=(kiwi::XY&&) = default;
		~XY() = default;

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

		XYZ() = default;
		XYZ(const kiwi::XYZ&) = default;
		kiwi::XYZ& operator=(const kiwi::XYZ&) = default;
		XYZ(kiwi::XYZ&&) = default;
		kiwi::XYZ& operator=(kiwi::XYZ&&) = default;
		~XYZ() = default;

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
		UV(const kiwi::UV&) = default;
		kiwi::UV& operator=(const kiwi::UV&) = default;
		UV(kiwi::UV&&) = default;
		kiwi::UV& operator=(kiwi::UV&&) = default;
		~UV() = default;

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

		RMEC() = default;
		RMEC(const kiwi::RMEC&) = default;
		kiwi::RMEC& operator=(const kiwi::RMEC&) = default;
		RMEC(kiwi::RMEC&&) = default;
		kiwi::RMEC& operator=(kiwi::RMEC&&) = default;
		~RMEC() = default;

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

		ECx() = default;
		ECx(const kiwi::ECx&) = default;
		kiwi::ECx& operator=(const kiwi::ECx&) = default;
		ECx(kiwi::ECx&&) = default;
		kiwi::ECx& operator=(kiwi::ECx&&) = default;
		~ECx() = default;

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
}


// INLINE IMPLEMENTATION

inline kiwi::RGBA::RGBA(GLfloat R, GLfloat G, GLfloat B) noexcept : m_RGBA{ R, G, B, 1.0f } {}
inline kiwi::RGBA::RGBA(GLfloat R, GLfloat G, GLfloat B, GLfloat A) noexcept : m_RGBA{ R, G, B, A } {}
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
inline GLfloat& kiwi::ECx::operator[](std::size_t offset) noexcept { return m_ECx[offset]; }
inline const GLfloat& kiwi::ECx::operator[](std::size_t offset) const noexcept { return m_ECx[offset]; }
inline GLfloat& kiwi::ECx::Ex() noexcept { return m_ECx[0]; }
inline const GLfloat& kiwi::ECx::Ex() const noexcept { return m_ECx[0]; }
inline GLfloat& kiwi::ECx::Cx() noexcept { return m_ECx[1]; }
inline const GLfloat& kiwi::ECx::Cx() const noexcept { return m_ECx[1]; }
inline GLfloat* kiwi::ECx::data() noexcept { return static_cast<GLfloat*>(m_ECx); }
inline const GLfloat* kiwi::ECx::data() const noexcept { return static_cast<const GLfloat*>(m_ECx); }

#endif // _KIWI_BASIC_DATA_HPP