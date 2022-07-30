#include <imgui/imgui.h>

#include "editor/browser/state.hpp"

namespace skye2d::editor::browser {

    void draw(State& state) {
        // ImGui::Begin("Open project");
        
        // if (ImGui::Button("New Project")) {
        //     state.projectWizard = true;
        // }

        // ImGui::End();
        
        // if (state.projectWizard) {
        //     ImGui::Begin("New Project");

        //     ImGui::End();
        // }
        ImGui::ShowDemoWindow();
    }

}