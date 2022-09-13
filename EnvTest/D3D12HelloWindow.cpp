#include "D3D12HelloWindow.h"

void D3D12HelloWindow::OnInit()
{
	//初始化-管道
	LoadPipeline();
	//初始化-资产
	LoadAssets();
}
// Update frame-based values.
void D3D12HelloWindow::OnUpdate()
{
	//更新自上一帧以来应更改的所有内容。
	//根据需要修改常量、顶点、索引缓冲区和其他所有内容。
}
// Render the scene.
void D3D12HelloWindow::OnRender()
{
	//填充命令列表
	PopulateCommandList();
	//执行命令列表
	//展示当前帧
	//等待 GPU 完成
}

void D3D12HelloWindow::OnDestroy()
{
	//干净地关闭应用程序
	//等待 GPU 完成
	//关闭事件句柄
}


void D3D12HelloWindow::LoadPipeline() {
	//启动调试层
	//创建设备
	//创建命令队列
	//创建交换链
	//创建渲染目标视图 (RTV) 描述符堆
	//创建帧资源（每个帧的渲染目标视图）
	//创建一个命令分配器

}
void D3D12HelloWindow::LoadAssets() {
	//创建一个空的根签名
	//编译着色器
	//创建顶点输入布局
	//创建管道状态对象描述，然后创建对象
	//创建命令列表
	//关闭命令列表
	//创建并加载顶点缓冲区
	//创建顶点缓冲区视图
	//创建一个栅栏
	//创建事件句柄
	//等待 GPU 完成
}

void D3D12HelloWindow::PopulateCommandList() {
	//重置命令列表分配器
	//重置命令列表
	//设置图形根签名
	//设置视口和剪刀矩形
	//设置资源屏障，指示后台缓冲区将用作渲染目标
	//将命令记录到命令列表中
	//指示在命令列表执行后将使用后台缓冲区呈现
	//关闭命令列表以进一步记录
}