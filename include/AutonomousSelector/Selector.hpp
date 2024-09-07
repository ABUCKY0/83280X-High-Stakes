#ifndef MARBLE_UI_H
#define MARBLE_UI_H

#include "Constants.hpp"
#include "main.h" // IWYU pragma: keep


// Function declarations
lv_res_t mar_onMatchConfirmPress(lv_obj_t *btn);
lv_res_t mar_onSkillsConfirmPress(lv_obj_t *btn);
lv_res_t mar_m_btn_action_skills(lv_obj_t *btn);
lv_res_t mar_m_btn_action_match(lv_obj_t *btn);
lv_res_t mar_s_btn_action_skills(lv_obj_t *btn);
lv_res_t mar_s_btn_action_match(lv_obj_t *btn);
void init_marble_ui();
void create_tasks();
void task_updui(void *param);
void task_updvar(void *param);
extern int estpsi;

#endif // MARBLE_UI_H