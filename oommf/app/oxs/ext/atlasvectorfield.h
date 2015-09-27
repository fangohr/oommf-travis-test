/* FILE: atlasvectorfield.h      -*-Mode: c++-*-
 *
 * Atlas vector field object, derived from Oxs_VectorField
 * class.
 *
 */

#ifndef _OXS_ATLASVECTORFIELD
#define _OXS_ATLASVECTORFIELD

#include "oc.h"
#include "nb.h"

#include "atlas.h"
#include "vectorfield.h"

OC_USE_STD_NAMESPACE;

/* End includes */

// Struct for use inside Oxs_AtlasVectorField class only.
// Defined outside that class to please MSVC++ 5.0.
struct OxsAVFSpecifiedValue {
  OC_BOOL value_is_set;
  Oxs_OwnedPointer<Oxs_VectorField> field_init;
  OxsAVFSpecifiedValue() : value_is_set(0) {}
};
// The next 3 operators are defined so MSVC++ 5.0 will accept
// vector<OxsAVFSpecifiedValue>, but are left undefined because
// they aren't needed.
OC_BOOL operator<(const OxsAVFSpecifiedValue&,const OxsAVFSpecifiedValue&);
OC_BOOL operator>(const OxsAVFSpecifiedValue&,const OxsAVFSpecifiedValue&);
OC_BOOL operator==(const OxsAVFSpecifiedValue&,const OxsAVFSpecifiedValue&);

class Oxs_AtlasVectorField:public Oxs_VectorField {
private:
  OC_BOOL set_norm;
  OC_REAL8m norm;
  OC_REAL8m multiplier;
  Oxs_OwnedPointer<Oxs_Atlas> atlas_obj; // Atlas basket
  Oxs_Key<Oxs_Atlas> atlas_key;
  Nb_ArrayWrapper<OxsAVFSpecifiedValue> values;
  OxsAVFSpecifiedValue default_value;
public:
  virtual const char* ClassName() const; // ClassName() is
  /// automatically generated by the OXS_EXT_REGISTER macro.

  Oxs_AtlasVectorField
  (const char* name,     // Child instance id
   Oxs_Director* newdtr, // App director
   const char* argstr);  // MIF input block parameters

  virtual ~Oxs_AtlasVectorField() {}

  virtual void Value(const ThreeVector& pt,
		     ThreeVector& export_value) const;

  virtual void FillMeshValue(const Oxs_Mesh* mesh,
			     Oxs_MeshValue<ThreeVector>& array) const {
    DefaultFillMeshValue(mesh,array);
  }
};

#endif // _OXS_ATLASVECTORFIELD