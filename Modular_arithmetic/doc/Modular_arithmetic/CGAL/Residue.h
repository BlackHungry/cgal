
namespace CGAL {

/*!
\ingroup PkgModularArithmetic
\anchor Residue 

\brief The class `Residue` represents a finite field \f$ \Z{/p\Z}\f$, 
for some prime number \f$ p\f$. 

The prime number \f$ p\f$ is stored in a static member variable. 
The class provides static member functions to change this value. 
However, already existing objects do not lose their value with respect to the 
old prime and can be reused after restoring the old prime. 
Since the type is based on double 
arithmetic the prime is restricted to values less than \f$ 2^{26}\f$. 
The initial value of \f$ p\f$ is 67111067. 

\attention Note that changing the prime invalidates already existing objects 
of this type.

Please note that the implementation of class `Residue` requires a mantissa 
precision according to the IEEE Standard for Floating-Point Arithmetic (IEEE 754). 
However, on some processors the traditional FPU uses an extended precision. Hence, it 
is indispensable that the proper mantissa length is enforced before performing 
any arithmetic operations. Moreover, it is required that numbers are rounded to the 
next nearest value. This can be ensured using `Protect_FPU_rounding` with 
`CGAL_FE_TONEAREST`, which also enforces the required precision as a side effect. 

In case the flag `CGAL_HAS_THREADS` 
is undefined the prime is just stored in a static member 
of the class, that is, `Residue` is not thread-safe in this case. 
In case `CGAL_HAS_THREADS` 
the implementation of the class is thread safe using 
`boost::thread_specific_ptr`. However, this may cause some performance 
penalty. Hence, it may be advisable to configure %CGAL with 
`CGAL_HAS_NO_THREADS`.   See Section  \ref Preliminaries_thread_safety "Thread Safety" 
in the preliminaries.

\cgalModels `Field`

*/

class Residue {
public:

/// \name Creation 
/// @{

/*! 
introduces a variable `x`, which is initialized with zero.
*/ 
Residue(); 

/*! 
copy constructor.
*/ 
Residue(const Residue& m); 

/*! 
introduces a variable `x`, which is initialized with \f$ i \mod p\f$.
*/ 
Residue(int i); 

/*! 
introduces a variable `x`, which is initialized with \f$ i \mod p\f$.
*/ 
Residue(long i); 

/// @} 

/// \name Operations 
/// @{

/*! 

Static member function which sets the current prime to the given value and returns the old prime. 
*/ 
static int set_current_prime(int p); 

/*! 

Static member function; 

returns the value of the current prime. 

*/ 
static int get_current_prime(); 

/*! 

Returns the unique representative of `x` within the range 
\f$ [-p/2,p/2]\f$, where \f$ p\f$ is the current prime. 

*/ 
int get_value() const; 

/*! 

*/ 
Residue operator+(Residue a); 

/*! 

*/ 
Residue operator-(Residue a); 

/*! 

*/ 
Residue operator+(Residue a,Residue b); 

/*! 

*/ 
Residue operator-(Residue a,Residue b); 

/*! 

*/ 
Residue operator*(Residue a,Residue b); 

/*! 

*/ 
Residue operator/(Residue a,Residue b); 

/*! 

*/ 
Residue & operator+=(Residue a); 

/*! 

*/ 
Residue & operator-=(Residue a); 

/*! 

*/ 
Residue & operator*=(Residue a); 

/*! 

*/ 
Residue & operator/=(Residue a); 

/*! 

*/ 
Residue operator==(Residue a,Residue b); 

/*! 

*/ 
Residue operator!=(Residue a,Residue b); 

/// @}

}; /* end Residue */
} /* end namespace CGAL */
