#include <stdio.h>
#include <stdlib.h>
//           _.._        ,------------.
//        ,'      `.    (  毒瘤工程師👨‍💻 )
//       /  __) __` \    `-,----------'
//      (  (`-`(-')  ) _.-'
//      /)  \  = /  (
//     /'    |--' .  \
//    (  ,---|  `-.)__`
//     )(  `-.,--'   _`-.
//    '/,'          (  Uu",
//     (_       ,    `/,-' )
//     `.__,  : `-'/  /`--'
//       |     `--'  |
//       `   `-._   /
//        \        (
//        /\ .      \.
//       / |` \     ,-\
//      /  \| .)   /   \
//     ( ,'|\    ,'     :
//     | \,`.`--"/      }
//     `,'    \  |,'    /
//    / "-._   `-/      |
//    "-.   "-.,'|     ;
//   /        _/["---'""]
//  :        /  |"-     '
//  '           |      /
//              `      |
int main() {
    long long n, mn, t = 1;
    scanf("%lld", &n);
    for (mn = n; n != 1; n = (n & 1 ? 3 * n + 1 : n / 2), t++, mn = (mn > n ? mn : n)) {
    }
    printf("%lld %lld", t, mn);
}