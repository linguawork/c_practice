void pipe_cycle(t_job *job)
{
   char **res;
   res[0] = executable_left_comamnd(job->pipe);
   res[1] = executable_right_comamnd(job->pipe_next, res);
   while (job->job_next)
   {
       job = job->job_next;
       res[0] = executable_left_comamnd(job->pipe);
       if (job->pipe_next)
           res[1] = executable_right_comamnd(job->pipe_next, res);
   }
}
