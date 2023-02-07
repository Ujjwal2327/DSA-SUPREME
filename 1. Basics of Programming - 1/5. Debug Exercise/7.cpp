// Print following pattern.
// https://codehelp.notion.site/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2F4d7bd719-45fa-4854-931e-d4fc4f510ab4%2FScreenshot_2023-01-29_at_5.41.12_PM.png?id=4e001b13-fead-45c2-9b38-c1b774634ecf&table=block&spaceId=17c4f087-3d17-4d5f-b068-892a6803e330&width=560&userId=&cache=v2

#include<iostream>

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf("  ");
        }
        for (int j = i; j < 2*i; j++)
        {
            printf("%d ", j);
        }
        int ele = 2 * (i - 1);
        for (int j = 1; j <= i - 1; j++)
        {
            printf("%d ", ele--);
        }
        printf("\n");
    }
    return 0;
}