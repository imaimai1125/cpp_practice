//クラスの宣言
#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_ 

#include <vector>
//タスク管理クラス
class TaskManager{
public:
	//タスク関数のinterface
	//falseを返したらタスクを削除
	typedef bool(*FpTask)();
private:
	//タスクを保存する配列の型とそのサイズを表す型
	typedef std::vector<FpTask> TaskArray;
	typedef TaskArray::size_type SizeType;
public:
	void Execute();  //タスク実行
	void Register(FpTask task); //タスク登録
private:
	void Unregister(SizeType id); //タスク登録解除
private:
	TaskArray m_task; //タスクを保存する配列
};

#endif //TASKMANAGER_H_