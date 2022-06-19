#pragma once

namespace rp{ namespace hal{

Thread Thread::create(thread_proc_t proc, void * data)
{
    Thread newborn(proc, data);
    
    return newborn;
}

u_result Thread::terminate()
{
	return RESULT_OK;
}

u_result Thread::setPriority( priority_val_t p)
{
    return  RESULT_OK;
}

Thread::priority_val_t Thread::getPriority()
{
    return PRIORITY_NORMAL;
}

u_result Thread::join(unsigned long timeout)
{
	return RESULT_OK;
}

}}
