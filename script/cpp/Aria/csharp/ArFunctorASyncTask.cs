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

public class ArFunctorASyncTask : ArASyncTask {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  public ArFunctorASyncTask(global::System.IntPtr cPtr, bool cMemoryOwn) : base(AriaCSPINVOKE.ArFunctorASyncTask_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(ArFunctorASyncTask obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~ArFunctorASyncTask() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          AriaCSPINVOKE.delete_ArFunctorASyncTask(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public ArFunctorASyncTask(ArRetFunctor1_VoidP_VoidP functor) : this(AriaCSPINVOKE.new_ArFunctorASyncTask(ArRetFunctor1_VoidP_VoidP.getCPtr(functor)), true) {
  }

  public override SWIGTYPE_p_void runThread(SWIGTYPE_p_void arg) {
    global::System.IntPtr cPtr = AriaCSPINVOKE.ArFunctorASyncTask_runThread(swigCPtr, SWIGTYPE_p_void.getCPtr(arg));
    SWIGTYPE_p_void ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_void(cPtr, false);
    return ret;
  }

}

}