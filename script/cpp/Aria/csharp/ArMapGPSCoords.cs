//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.8
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace AriaCS {

public class ArMapGPSCoords : ArENUCoords {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  public ArMapGPSCoords(global::System.IntPtr cPtr, bool cMemoryOwn) : base(AriaCSPINVOKE.ArMapGPSCoords_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(ArMapGPSCoords obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~ArMapGPSCoords() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          AriaCSPINVOKE.delete_ArMapGPSCoords(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public ArMapGPSCoords(ArLLACoords org) : this(AriaCSPINVOKE.new_ArMapGPSCoords__SWIG_0(ArLLACoords.getCPtr(org)), true) {
    if (AriaCSPINVOKE.SWIGPendingException.Pending) throw AriaCSPINVOKE.SWIGPendingException.Retrieve();
  }

  public ArMapGPSCoords() : this(AriaCSPINVOKE.new_ArMapGPSCoords__SWIG_1(), true) {
  }

  public bool convertMap2LLACoords(double ea, double no, double up, SWIGTYPE_p_double lat, SWIGTYPE_p_double lon, SWIGTYPE_p_double alt) {
    bool ret = AriaCSPINVOKE.ArMapGPSCoords_convertMap2LLACoords(swigCPtr, ea, no, up, SWIGTYPE_p_double.getCPtr(lat), SWIGTYPE_p_double.getCPtr(lon), SWIGTYPE_p_double.getCPtr(alt));
    if (AriaCSPINVOKE.SWIGPendingException.Pending) throw AriaCSPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool convertLLA2MapCoords(double lat, double lon, double alt, SWIGTYPE_p_double ea, SWIGTYPE_p_double no, SWIGTYPE_p_double up) {
    bool ret = AriaCSPINVOKE.ArMapGPSCoords_convertLLA2MapCoords__SWIG_0(swigCPtr, lat, lon, alt, SWIGTYPE_p_double.getCPtr(ea), SWIGTYPE_p_double.getCPtr(no), SWIGTYPE_p_double.getCPtr(up));
    if (AriaCSPINVOKE.SWIGPendingException.Pending) throw AriaCSPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool convertLLA2MapCoords(ArLLACoords lla, SWIGTYPE_p_double ea, SWIGTYPE_p_double no, SWIGTYPE_p_double up) {
    bool ret = AriaCSPINVOKE.ArMapGPSCoords_convertLLA2MapCoords__SWIG_1(swigCPtr, ArLLACoords.getCPtr(lla), SWIGTYPE_p_double.getCPtr(ea), SWIGTYPE_p_double.getCPtr(no), SWIGTYPE_p_double.getCPtr(up));
    if (AriaCSPINVOKE.SWIGPendingException.Pending) throw AriaCSPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void setOrigin(ArLLACoords org) {
    AriaCSPINVOKE.ArMapGPSCoords_setOrigin(swigCPtr, ArLLACoords.getCPtr(org));
    if (AriaCSPINVOKE.SWIGPendingException.Pending) throw AriaCSPINVOKE.SWIGPendingException.Retrieve();
  }

  public ArECEFCoords myOriginECEF {
    set {
      AriaCSPINVOKE.ArMapGPSCoords_myOriginECEF_set(swigCPtr, ArECEFCoords.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = AriaCSPINVOKE.ArMapGPSCoords_myOriginECEF_get(swigCPtr);
      ArECEFCoords ret = (cPtr == global::System.IntPtr.Zero) ? null : new ArECEFCoords(cPtr, false);
      return ret;
    } 
  }

  public ArLLACoords myOriginLLA {
    set {
      AriaCSPINVOKE.ArMapGPSCoords_myOriginLLA_set(swigCPtr, ArLLACoords.getCPtr(value));
    } 
    get {
      global::System.IntPtr cPtr = AriaCSPINVOKE.ArMapGPSCoords_myOriginLLA_get(swigCPtr);
      ArLLACoords ret = (cPtr == global::System.IntPtr.Zero) ? null : new ArLLACoords(cPtr, false);
      return ret;
    } 
  }

  public bool myOriginSet {
    set {
      AriaCSPINVOKE.ArMapGPSCoords_myOriginSet_set(swigCPtr, value);
    } 
    get {
      bool ret = AriaCSPINVOKE.ArMapGPSCoords_myOriginSet_get(swigCPtr);
      return ret;
    } 
  }

}

}