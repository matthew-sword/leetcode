#include <stdio.h>
#include <stdlib.h>

//邻接表的边链表
typedef struct e_node{
int vertex; //图的顶点
struct e_node* next_edge;
} EDGE;

//邻接表的顶点
typedef struct v_node{
    int in_deg;   //顶点入度
    EDGE* first_edge;   //从顶点出发的第一条边
} VERTEX;

//邻接表
typedef struct g_node{
    int ver_num;    //顶点数
    int edg_num;    //边数
    VERTEX* vertex;
} GRAPH;

int canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize);

//转化为邻接表
GRAPH* creat_adj_list(int numCourses, int** prerequisites, int prerequisitesRowSize);


int main()
{
    int n = 3;
    int** course = NULL;
    course = (int**) malloc(sizeof(int*)*n);

    for (int i = 0; i < n; i++)
    {
        course[i] = (int*) malloc(sizeof(int)*2);
    }

    course[0][0] = 0;
    course[0][1] = 2;

    course[1][0] = 1;
    course[1][1] = 2;

    course[2][0] = 2;
    course[2][1] = 0;



    int result = canFinish(n,course,3,2);
    printf("%d",result);

    return 0;
}

int canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize)
{
    //创建有向图的邻接表
    GRAPH* courses;
    courses = creat_adj_list(numCourses, prerequisites, prerequisitesRowSize);

    int rest_v = numCourses;  //剩余顶点数
    int total_in = 0;   //总的入度
    int del;    //记录将要删除的点
    int flag = 0;   //是否成环的标记
    int can_topo;   //是否可以进行拓扑的标记

    //计算总入度
    for (int i = 0; i < numCourses ; i++)
        total_in += courses->vertex[i].in_deg;

    //进行拓扑排序，广度优先搜索
    while (total_in)
    {
        can_topo = 0;
        for (int i = 0; i < numCourses ; i++)
        {
            //从入度为0的点开始进行删除
            if (courses->vertex[i].in_deg == 0 && courses->vertex[i].first_edge != NULL)
            {
                can_topo =1;
                while (courses->vertex[i].first_edge)   //依次删除从该顶点出发的边,！！！没有进行内存回收
                {
                    del = courses->vertex[i].first_edge->vertex;
                    courses->vertex[del].in_deg--;
                    total_in--;
                    courses->vertex[i].first_edge = courses->vertex[i].first_edge->next_edge;

                    //异或，判断是否构成成环条件
                    if ( (!courses->vertex[del].in_deg && courses->vertex[del].first_edge)
                       || (courses->vertex[del].in_deg && !courses->vertex[del].first_edge) )
                        flag --;
                }
                rest_v--;
            }
                //判断是否构成成环条件
            else if (courses->vertex[i].in_deg != 0 && courses->vertex[i].first_edge != NULL)
                flag ++;
        }

        //有环，返回false
        if (flag == rest_v || !can_topo)
            return 0;
    }

    return 1;
}

GRAPH* creat_adj_list(int numCourses, int** prerequisites, int prerequisitesRowSize)
{
    GRAPH* graph;
    EDGE* now = NULL;
    EDGE* next = NULL;
    int from, to;

    //初始化邻接表
    if ( (graph = (GRAPH*)malloc(sizeof(GRAPH))) == NULL )
        return NULL;

    graph->ver_num = numCourses;
    graph->edg_num = prerequisitesRowSize;
    graph->vertex = (VERTEX*)malloc(sizeof(VERTEX)*numCourses);

    //初始化顶点
    for (int i = 0; i < graph->ver_num; i++)
    {
        graph->vertex[i].in_deg = 0;
        graph->vertex[i].first_edge = NULL;
    }

    //初始化边
    for (int j = 0; j < graph->edg_num; j++)
    {
        from = prerequisites[j][1];
        to   = prerequisites[j][0];

        graph->vertex[to].in_deg++;     //记录每个顶点入度

        now = (EDGE*)malloc(sizeof(EDGE));
        now->vertex = to;
        now->next_edge = NULL;

        //连接链表
        if (graph->vertex[from].first_edge == NULL)
            graph->vertex[from].first_edge = now;

        else
        {
            next = graph->vertex[from].first_edge;
            while (next->next_edge)
                next = next->next_edge;

            next->next_edge = now;
        }
    }

    return graph;
}


