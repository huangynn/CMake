/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#ifndef cmTargetCompileOptionsCommand_h
#define cmTargetCompileOptionsCommand_h

#include "cmConfigure.h"

#include <string>
#include <vector>

#include "cmTargetPropCommandBase.h"

class cmCommand;
class cmExecutionStatus;
class cmTarget;

class cmTargetCompileOptionsCommand : public cmTargetPropCommandBase
{
public:
  /**
   * This is a virtual constructor for the command.
   */
  cmCommand* Clone() CM_OVERRIDE { return new cmTargetCompileOptionsCommand; }

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  bool InitialPass(std::vector<std::string> const& args,
                   cmExecutionStatus& status) CM_OVERRIDE;

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  std::string GetName() const CM_OVERRIDE { return "target_compile_options"; }

private:
  void HandleImportedTarget(const std::string& tgt) CM_OVERRIDE;
  void HandleMissingTarget(const std::string& name) CM_OVERRIDE;

  bool HandleDirectContent(cmTarget* tgt,
                           const std::vector<std::string>& content,
                           bool prepend, bool system) CM_OVERRIDE;
  std::string Join(const std::vector<std::string>& content) CM_OVERRIDE;
};

#endif
