#pragma once
#include <cstdint>
#include <map>
#include <string>
#include <vector>
struct mrow { // ข้อข้ มูล 1 เครื่อรื่ง ณ วินวิ าทีนี้ (คัดมาจาก snapshot)
std::string id, status;
double rx = 0, tx = 0;
};
struct alert { // 1 แจ้งจ้ เตือนของกลุ่มลุ่
std::string kind, group;
int n = 0, total = 0;
int64_t since = 0;
std::vector<std::string> ids;
};
struct counter { // สถานะจำ ต่อ (กลุ่มลุ่ , ชนิด)
int on = 0, off = 0;
bool active = false;
int64_t since = 0;
};
struct astate { // เจ้าจ้ของคือลูปลู หลักเท่านั้นนั้ ไม่ต้ม่ ต้องใช้ mutex
std::map<std::string, counter> c; // key = kind + "|" + group
};
std::string group_of(const std::string& id);
std::vector<alert> eval_alerts(const std::vector<mrow>& rows, astate& st,
int64_t now);
