/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef TMVAWRAPPER
#define TMVAWRAPPER

#include "RooAbsReal.h"
#include "RooArgList.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
#include "RooListProxy.h"

#include "TDOMParser.h"
#include "TXMLNode.h"
#include <iostream>
#include "TList.h"
#include "TXMLAttr.h"

#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#endif


/*namespace TMVA {
    class Reader;
}
*/

class TMVAWrapper : public RooAbsReal {
public:
  TMVAWrapper() {} ; 
  //  TMVAWrapper(const char *name, const char *title,
  //	      RooAbsReal& _features, RooAbsReal& _param);
  TMVAWrapper(const TMVAWrapper& other, const char* name=0) ;
  TMVAWrapper(const char *name, const char *title, RooArgList &ral,char weightfile[100]);

  virtual TObject* clone(const char* newname) const { return new TMVAWrapper(*this,newname); }
  inline virtual ~TMVAWrapper() { }


protected:

  // number of input features
  int num_features;

  // feature names, from XML, used to connect to RooStuff
  std::vector<TString> names;

  // evaluate the NN
  Double_t evaluate() const ;

  // name of the weights file
  char weights[1000];

private:

  // extract info from XML
  // looks like order of RooArgList needs to be same as in the XML file
  void findVariables(TXMLNode *node);
  void getListOfVars(char weights[1000]);
  
  TMVA::Reader *reader ;

  // input variable storage space
  const static int _max_vars=1000;
  mutable Float_t local_features[_max_vars];

  // result
  Float_t target;

  // connection to Roo inputs
  RooListProxy _actualVars;

  ClassDef(TMVAWrapper,1) // Your description goes here...
};
 
#endif
