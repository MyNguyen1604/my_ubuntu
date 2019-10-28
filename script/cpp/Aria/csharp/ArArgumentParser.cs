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

public class ArArgumentParser : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  public ArArgumentParser(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(ArArgumentParser obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~ArArgumentParser() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          AriaCSPINVOKE.delete_ArArgumentParser(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public ArArgumentParser(SWIGTYPE_p_int argc, SWIGTYPE_p_p_char argv) : this(AriaCSPINVOKE.new_ArArgumentParser__SWIG_0(SWIGTYPE_p_int.getCPtr(argc), SWIGTYPE_p_p_char.getCPtr(argv)), true) {
  }

  public ArArgumentParser(ArArgumentBuilder builder) : this(AriaCSPINVOKE.new_ArArgumentParser__SWIG_1(ArArgumentBuilder.getCPtr(builder)), true) {
  }

  public void setWasReallySetOnlyTrue(bool wasReallySetOnlyTrue) {
    AriaCSPINVOKE.ArArgumentParser_setWasReallySetOnlyTrue(swigCPtr, wasReallySetOnlyTrue);
  }

  public bool getWasReallySetOnlyTrue() {
    bool ret = AriaCSPINVOKE.ArArgumentParser_getWasReallySetOnlyTrue(swigCPtr);
    return ret;
  }

  public bool checkArgument(string argument) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkArgument(swigCPtr, argument);
    return ret;
  }

  public string checkParameterArgument(string argument, bool returnFirst) {
    string ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgument__SWIG_0(swigCPtr, argument, returnFirst);
    return ret;
  }

  public string checkParameterArgument(string argument) {
    string ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgument__SWIG_1(swigCPtr, argument);
    return ret;
  }

  public bool checkParameterArgumentString(string argument, SWIGTYPE_p_p_char dest, SWIGTYPE_p_bool wasReallySet, bool returnFirst) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentString__SWIG_0(swigCPtr, argument, SWIGTYPE_p_p_char.getCPtr(dest), SWIGTYPE_p_bool.getCPtr(wasReallySet), returnFirst);
    return ret;
  }

  public bool checkParameterArgumentString(string argument, SWIGTYPE_p_p_char dest, SWIGTYPE_p_bool wasReallySet) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentString__SWIG_1(swigCPtr, argument, SWIGTYPE_p_p_char.getCPtr(dest), SWIGTYPE_p_bool.getCPtr(wasReallySet));
    return ret;
  }

  public bool checkParameterArgumentString(string argument, SWIGTYPE_p_p_char dest) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentString__SWIG_2(swigCPtr, argument, SWIGTYPE_p_p_char.getCPtr(dest));
    return ret;
  }

  public bool checkParameterArgumentInteger(string argument, SWIGTYPE_p_int dest, SWIGTYPE_p_bool wasReallySet, bool returnFirst) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentInteger__SWIG_0(swigCPtr, argument, SWIGTYPE_p_int.getCPtr(dest), SWIGTYPE_p_bool.getCPtr(wasReallySet), returnFirst);
    return ret;
  }

  public bool checkParameterArgumentInteger(string argument, SWIGTYPE_p_int dest, SWIGTYPE_p_bool wasReallySet) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentInteger__SWIG_1(swigCPtr, argument, SWIGTYPE_p_int.getCPtr(dest), SWIGTYPE_p_bool.getCPtr(wasReallySet));
    return ret;
  }

  public bool checkParameterArgumentInteger(string argument, SWIGTYPE_p_int dest) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentInteger__SWIG_2(swigCPtr, argument, SWIGTYPE_p_int.getCPtr(dest));
    return ret;
  }

  public bool checkParameterArgumentBool(string argument, SWIGTYPE_p_bool dest, SWIGTYPE_p_bool wasReallySet, bool returnFirst) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentBool__SWIG_0(swigCPtr, argument, SWIGTYPE_p_bool.getCPtr(dest), SWIGTYPE_p_bool.getCPtr(wasReallySet), returnFirst);
    return ret;
  }

  public bool checkParameterArgumentBool(string argument, SWIGTYPE_p_bool dest, SWIGTYPE_p_bool wasReallySet) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentBool__SWIG_1(swigCPtr, argument, SWIGTYPE_p_bool.getCPtr(dest), SWIGTYPE_p_bool.getCPtr(wasReallySet));
    return ret;
  }

  public bool checkParameterArgumentBool(string argument, SWIGTYPE_p_bool dest) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentBool__SWIG_2(swigCPtr, argument, SWIGTYPE_p_bool.getCPtr(dest));
    return ret;
  }

  public bool checkParameterArgumentFloat(string argument, SWIGTYPE_p_float dest, SWIGTYPE_p_bool wasReallySet, bool returnFirst) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentFloat__SWIG_0(swigCPtr, argument, SWIGTYPE_p_float.getCPtr(dest), SWIGTYPE_p_bool.getCPtr(wasReallySet), returnFirst);
    return ret;
  }

  public bool checkParameterArgumentFloat(string argument, SWIGTYPE_p_float dest, SWIGTYPE_p_bool wasReallySet) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentFloat__SWIG_1(swigCPtr, argument, SWIGTYPE_p_float.getCPtr(dest), SWIGTYPE_p_bool.getCPtr(wasReallySet));
    return ret;
  }

  public bool checkParameterArgumentFloat(string argument, SWIGTYPE_p_float dest) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentFloat__SWIG_2(swigCPtr, argument, SWIGTYPE_p_float.getCPtr(dest));
    return ret;
  }

  public bool checkParameterArgumentDouble(string argument, SWIGTYPE_p_double dest, SWIGTYPE_p_bool wasReallySet, bool returnFirst) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentDouble__SWIG_0(swigCPtr, argument, SWIGTYPE_p_double.getCPtr(dest), SWIGTYPE_p_bool.getCPtr(wasReallySet), returnFirst);
    return ret;
  }

  public bool checkParameterArgumentDouble(string argument, SWIGTYPE_p_double dest, SWIGTYPE_p_bool wasReallySet) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentDouble__SWIG_1(swigCPtr, argument, SWIGTYPE_p_double.getCPtr(dest), SWIGTYPE_p_bool.getCPtr(wasReallySet));
    return ret;
  }

  public bool checkParameterArgumentDouble(string argument, SWIGTYPE_p_double dest) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkParameterArgumentDouble__SWIG_2(swigCPtr, argument, SWIGTYPE_p_double.getCPtr(dest));
    return ret;
  }

  public void addDefaultArgument(string argument, int position) {
    AriaCSPINVOKE.ArArgumentParser_addDefaultArgument__SWIG_0(swigCPtr, argument, position);
  }

  public void addDefaultArgument(string argument) {
    AriaCSPINVOKE.ArArgumentParser_addDefaultArgument__SWIG_1(swigCPtr, argument);
  }

  public void addDefaultArgumentAsIs(string argument, int position) {
    AriaCSPINVOKE.ArArgumentParser_addDefaultArgumentAsIs__SWIG_0(swigCPtr, argument, position);
  }

  public void addDefaultArgumentAsIs(string argument) {
    AriaCSPINVOKE.ArArgumentParser_addDefaultArgumentAsIs__SWIG_1(swigCPtr, argument);
  }

  public void loadDefaultArguments(int positon) {
    AriaCSPINVOKE.ArArgumentParser_loadDefaultArguments__SWIG_0(swigCPtr, positon);
  }

  public void loadDefaultArguments() {
    AriaCSPINVOKE.ArArgumentParser_loadDefaultArguments__SWIG_1(swigCPtr);
  }

  public bool checkHelpAndWarnUnparsed(uint numArgsOkay) {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkHelpAndWarnUnparsed__SWIG_0(swigCPtr, numArgsOkay);
    return ret;
  }

  public bool checkHelpAndWarnUnparsed() {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkHelpAndWarnUnparsed__SWIG_1(swigCPtr);
    return ret;
  }

  public bool checkHelp() {
    bool ret = AriaCSPINVOKE.ArArgumentParser_checkHelp(swigCPtr);
    return ret;
  }

  public uint getArgc() {
    uint ret = AriaCSPINVOKE.ArArgumentParser_getArgc(swigCPtr);
    return ret;
  }

  public SWIGTYPE_p_p_char getArgv() {
    global::System.IntPtr cPtr = AriaCSPINVOKE.ArArgumentParser_getArgv(swigCPtr);
    SWIGTYPE_p_p_char ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_p_char(cPtr, false);
    return ret;
  }

  public ArArgumentBuilder getArgumentBuilder() {
    global::System.IntPtr cPtr = AriaCSPINVOKE.ArArgumentParser_getArgumentBuilder(swigCPtr);
    ArArgumentBuilder ret = (cPtr == global::System.IntPtr.Zero) ? null : new ArArgumentBuilder(cPtr, false);
    return ret;
  }

  public string getArg(uint whichArg) {
    string ret = AriaCSPINVOKE.ArArgumentParser_getArg(swigCPtr, whichArg);
    return ret;
  }

  public void log() {
    AriaCSPINVOKE.ArArgumentParser_log(swigCPtr);
  }

  public string getStartingArguments() {
    string ret = AriaCSPINVOKE.ArArgumentParser_getStartingArguments(swigCPtr);
    return ret;
  }

  public void removeArg(uint which) {
    AriaCSPINVOKE.ArArgumentParser_removeArg(swigCPtr, which);
  }

  public static void addDefaultArgumentFile(string file) {
    AriaCSPINVOKE.ArArgumentParser_addDefaultArgumentFile(file);
  }

  public static void addDefaultArgumentEnv(string env) {
    AriaCSPINVOKE.ArArgumentParser_addDefaultArgumentEnv(env);
  }

  public static void logDefaultArgumentLocations() {
    AriaCSPINVOKE.ArArgumentParser_logDefaultArgumentLocations();
  }

}

}