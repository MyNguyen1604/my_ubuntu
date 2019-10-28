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

public class ArMapSupplementInterface : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  public ArMapSupplementInterface(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(ArMapSupplementInterface obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~ArMapSupplementInterface() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          AriaCSPINVOKE.delete_ArMapSupplementInterface(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public virtual bool hasOriginLatLongAlt() {
    bool ret = AriaCSPINVOKE.ArMapSupplementInterface_hasOriginLatLongAlt(swigCPtr);
    return ret;
  }

  public virtual ArPose getOriginLatLong() {
    ArPose ret = new ArPose(AriaCSPINVOKE.ArMapSupplementInterface_getOriginLatLong(swigCPtr), true);
    return ret;
  }

  public virtual double getOriginAltitude() {
    double ret = AriaCSPINVOKE.ArMapSupplementInterface_getOriginAltitude(swigCPtr);
    return ret;
  }

  public virtual void setOriginLatLongAlt(bool hasOriginLatLong, ArPose originLatLong, double altitude, SWIGTYPE_p_ArMapChangeDetails changeDetails) {
    AriaCSPINVOKE.ArMapSupplementInterface_setOriginLatLongAlt__SWIG_0(swigCPtr, hasOriginLatLong, ArPose.getCPtr(originLatLong), altitude, SWIGTYPE_p_ArMapChangeDetails.getCPtr(changeDetails));
    if (AriaCSPINVOKE.SWIGPendingException.Pending) throw AriaCSPINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual void setOriginLatLongAlt(bool hasOriginLatLong, ArPose originLatLong, double altitude) {
    AriaCSPINVOKE.ArMapSupplementInterface_setOriginLatLongAlt__SWIG_1(swigCPtr, hasOriginLatLong, ArPose.getCPtr(originLatLong), altitude);
    if (AriaCSPINVOKE.SWIGPendingException.Pending) throw AriaCSPINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual void writeSupplementToFunctor(ArFunctor1_CString functor, string endOfLineChars) {
    AriaCSPINVOKE.ArMapSupplementInterface_writeSupplementToFunctor(swigCPtr, ArFunctor1_CString.getCPtr(functor), endOfLineChars);
  }

}

}