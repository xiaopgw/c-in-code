#include <stdio.h>
#include <stdlib.h>  // 用于 exit()

// 定义存档文件名
#define SAVE_FILE "save.dat"

// 保存函数：把分数写入文件
void save_score(int score) {
    // 1. 打开文件（"w" = 写入模式，如果文件不存在则创建）
    FILE *fp = fopen(SAVE_FILE, "w");
    if (fp == NULL) {
        printf("❌ 保存失败：无法创建文件！\n");
        return;
    }
    
    // 2. 把分数写入文件（%d 表示十进制整数，\n 换行）
    fprintf(fp, "%d\n", score);
    
    // 3. 关闭文件（重要！数据才会真正存到磁盘）
    fclose(fp);
    
    printf("✅ 已保存分数：%d\n", score);
}

// 加载函数：从文件读取分数，成功返回 1，失败返回 0
int load_score(int *score) {
    // 1. 打开文件（"r" = 读取模式）
    FILE *fp = fopen(SAVE_FILE, "r");
    if (fp == NULL) {
        // 文件不存在（第一次运行）不算错误，返回 0 表示没有存档
        return 0;
    }
    
    // 2. 从文件读取一个整数
    //    fscanf 返回值：成功读取的变量个数
    //    这里我们期望读 1 个整数，如果成功则返回 1
    if (fscanf(fp, "%d", score) == 1) {
        fclose(fp);
        return 1;  // 读取成功
    } else {
        // 文件内容格式不对
        fclose(fp);
        return 0;  // 读取失败
    }
}

int main() {
    int current_score;
    int has_loaded;
    
    printf("═══════════════════════════════════\n");
    printf("  存档演示程序（一个整数变量）\n");
    printf("═══════════════════════════════════\n\n");
    
    // ---- 第一步：尝试读取存档 ----
    has_loaded = load_score(&current_score);
    
    if (has_loaded) {
        printf("📂 读取存档成功！当前分数：%d\n", current_score);
    } else {
        printf("📄 没有找到存档，从 0 分开始。\n");
        current_score = 0;
    }
    
    // ---- 第二步：模拟游戏过程（让玩家修改分数） ----
    printf("\n当前分数：%d\n", current_score);
    printf("请输入新的分数（输入数字后按回车）：");
    scanf("%d", &current_score);
    
    // ---- 第三步：保存分数 ----
    save_score(current_score);
    
    printf("\n程序结束。你可以重新运行本程序，分数会被恢复。\n");
    return 0;
}