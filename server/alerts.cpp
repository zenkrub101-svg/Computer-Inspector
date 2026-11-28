#include "alerts.hpp"
constexpr int MIN_N = 3; // ต้องมากกว่าว่ นี้จึงจึจะเรียรีกว่าว่ "พร้อร้ มกัน"
constexpr double MIN_FRAC = 0.6;
constexpr double NET_KBPS = 3000;
constexpr int HOLD_OFF = 5; // วินวิ าทีต่อเนื่องก่อนขึ้นขึ้ group_offline
constexpr int HOLD_OTHER = 10; // สำ หรับรั group_net / group_load
constexpr int CLEAR_AFTER = 10; // วินวิ าทีที่ไม่จม่ ริงริติดกันก่อนเลิกเตือน
std::string group_of(const std::string& id) {
// TODO: หาขีดขี '-' ตัวสุดสุ ท้ายด้วด้ ย rfind; ไม่เม่ จอหรือรือยู่ตำยู่ ตำ แหน่งแรก -> "(ไม่รม่ ะบุ)"
}
static bool is_hit(const std::string& kind, const mrow& r) {
if (kind == "group_offline") return r.status == "offline";
if (kind == "group_load") return r.status == "crit";
if (kind == "group_net") return r.rx >= NET_KBPS || r.tx >= NET_KBPS;
return false;
}
std::vector<alert> eval_alerts(const std::vector<mrow>& rows, astate& st,
int64_t now) {
std::vector<alert> out;
// 1) แบ่งบ่ เครื่อรื่งเข้าข้กลุ่มลุ่ : std::map<std::string, std::vector<const mrow*>> g;
// 2) วนทุกทุ กลุ่มลุ่ x ทุกทุ kind: นับ hit = จำ นวนเครื่อรื่งที่ is_hit เป็นป็ จริงริ
// cond = (total >= MIN_N && hit >= MIN_N && hit >= total * MIN_FRAC)
// 3) อัปเดต counter: cond ? (++on, off = 0) : (++off, on = 0)
// เปิดปิ active เมื่อมื่ on >= HOLD (ตั้งตั้ since = now ครั้งรั้แรกเท่านั้นนั้ ); ปิดเมื่อมื่ off >=
CLEAR_AFTER
// 4) active -> push_back alert (จำ กัด ids ไม่เม่ กิน 50)
// 5) ลบ counter ของกลุ่มลุ่ ที่ไม่มีม่ เมีครื่อรื่งแล้ว (กัน map บวม)
return out;
}
