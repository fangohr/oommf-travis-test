/* FILE: uniaxialanisotropy4.h            -*-Mode: c++-*-
 *
 * Uniaxial Anisotropy, derived from Oxs_Energy class.
 *
 * This interface is a modification of the interface
 * /oommf/app/oxs/ext/uniaxialanisotropy.h
 * It is designed for handling higher orders of the 
 * power series of the uniaxial anisotropy
 * The required arguments are 
 * -scalar 'K1' (for second order power)
 * -scalar 'K2' (for fourth order power),
 * -vector 'axis' indicating the theta = 0 anisotropy direction
 *
 * Juergen Zimmermann
 * Computational Engineering and Design Group
 * (c) 2004 University of Southampton
 * 
 * file created Wed July 7 2004
 *
 * file updated Thu April 19 2007: 
 * renaming issues  Ced_UniaxialAnisotropy to Southampton_UniaxialAnisotropy4
 * and renormalising K1 and K2
 */

#ifndef _OXS_UNIAXIALANISOTROPY4
#define _OXS_UNIAXIALANISOTROPY4

#include "nb.h"
#include "threevector.h"
#include "energy.h"
#include "key.h"
#include "simstate.h"
#include "mesh.h"
#include "meshvalue.h"
#include "scalarfield.h"
#include "vectorfield.h"

/* End includes */

class Southampton_UniaxialAnisotropy4:public Oxs_Energy {
private:
  Oxs_OwnedPointer<Oxs_ScalarField> K1_init;
  Oxs_OwnedPointer<Oxs_ScalarField> K2_init;
  Oxs_OwnedPointer<Oxs_VectorField> axis_init;
  mutable OC_UINT4m mesh_id;
  mutable Oxs_MeshValue<OC_REAL8m> K1;
  mutable Oxs_MeshValue<OC_REAL8m> K2;  // K2: correction term: forth order in fourier series
  mutable Oxs_MeshValue<ThreeVector> axis;
  /// K1, K2, and axis are cached values filled by corresponding
  /// *_init members when a change in mesh is detected.

  enum IntegrationMethod {
    UNKNOWN_INTEG, RECT_INTEG, QUAD_INTEG
  } integration_method;
  /// Integration formulation to use.  "unknown" is invalid; it
  /// is defined for error detection.

protected:
  virtual void GetEnergy(const Oxs_SimState& state,
			 Oxs_EnergyData& oed) const;

public:
  virtual const char* ClassName() const; // ClassName() is
  /// automatically generated by the OXS_EXT_REGISTER macro.
  Southampton_UniaxialAnisotropy4(const char* name,  // Child instance id
				  Oxs_Director* newdtr, // App director
				  const char* argstr);  // MIF input block parameters

  virtual ~Southampton_UniaxialAnisotropy4() {}
};


#endif // _OXS_UNIAXIALANISOTROPY4
