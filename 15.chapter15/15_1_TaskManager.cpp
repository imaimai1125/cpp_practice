#include "15_1_TaskManager.h"

//タスクの実行
void TaskManager::Execute(){
	for (int i = 0; i < m_task.size();){
		if(m_task[i]()){
			++i;
		}else{
			Unregister(i);
		}
	}
}
//タスクの登録
void TaskManager::Register(FpTask task){
	m_task.push_back(task);
}

//タスクの登録解除
void TaskManager::Unregister(SizeType id){
	SizeType size = m_task.size();
	//先頭から先にずらしていく
	for (SizeType i = id+1; i < size; ++i){
		m_task[i-1] = m_task[i];
	}
	m_task.resize(size -1);
}