/**
 * This file is created at Almende B.V. It is open-source software and part of the Common 
 * Hybrid Agent Platform (CHAP). A toolbox with a lot of open-source tools, ranging from 
 * thread pools and TCP/IP components to control architectures and learning algorithms. 
 * This software is published under the GNU Lesser General Public license (LGPL).
 *
 * It is not possible to add usage restrictions to an open-source license. Nevertheless,
 * we personally strongly object against this software being used by the military, in the
 * bio-industry, for animal experimentation, or anything that violates the Universal
 * Declaration of Human Rights.
 *
 * Copyright (c) 2012 Anne van Rossum <anne@almende.com>
 *
 * @author  Anne C. van Rossum
 * @company Almende B.V.
 */

#include <string>
#include <vector>

namespace Rur {

struct Param {
  int sensor_id;
};

class SumModule {
private:
  
  int dummyInput;
  
  Param *cliParam;

public:
  SumModule() {
    cliParam = new Param();
  }
  
  ~SumModule() { }
  
  void Tick();
  
  void Init(std::string & name) { }
  
  // Function to get Param struct (to subsequently set CLI parameters)
  inline Param *GetParam() { return cliParam; };
  
  inline int *readInput() {
    return &dummyInput;
  }
  
  inline void writeOutput(const int data_out) {
  }
  
};
}

