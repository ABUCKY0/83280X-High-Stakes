#ifndef SELECTOR_H
#define SELECTOR_H

#include "Constants.hpp"
#include "main.h" // IWYU pragma: keep


void mogoActuation();
void sweeperActuation();


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

#endif // SELECTOR_H