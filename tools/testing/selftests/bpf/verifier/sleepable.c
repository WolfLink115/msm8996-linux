{
	"sleepable fentry accept",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_TRACING,
	.expected_attach_type = BPF_TRACE_FENTRY,
	.kfunc = "bpf_fentry_test1",
	.result = ACCEPT,
	.flags = BPF_F_SLEEPABLE,
	.runs = -1,
},
{
	"sleepable fexit accept",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_TRACING,
	.expected_attach_type = BPF_TRACE_FENTRY,
	.kfunc = "bpf_fentry_test1",
	.result = ACCEPT,
	.flags = BPF_F_SLEEPABLE,
	.runs = -1,
},
{
	"sleepable fmod_ret accept",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_TRACING,
	.expected_attach_type = BPF_MODIFY_RETURN,
	.kfunc = "bpf_fentry_test1",
	.result = ACCEPT,
	.flags = BPF_F_SLEEPABLE,
	.runs = -1,
},
{
	"sleepable iter accept",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_TRACING,
	.expected_attach_type = BPF_TRACE_ITER,
	.kfunc = "task",
	.result = ACCEPT,
	.flags = BPF_F_SLEEPABLE,
	.runs = -1,
},
{
	"sleepable lsm accept",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_LSM,
	.kfunc = "bpf",
	.expected_attach_type = BPF_LSM_MAC,
	.result = ACCEPT,
	.flags = BPF_F_SLEEPABLE,
	.runs = -1,
},
{
	"sleepable uprobe accept",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_KPROBE,
	.kfunc = "bpf_fentry_test1",
	.result = ACCEPT,
	.flags = BPF_F_SLEEPABLE,
	.runs = -1,
},
{
	"sleepable raw tracepoint reject",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_TRACING,
	.expected_attach_type = BPF_TRACE_RAW_TP,
	.kfunc = "sched_switch",
	.result = REJECT,
	.errstr = "Only fentry/fexit/fmod_ret, lsm, iter, uprobe, and struct_ops programs can be sleepable",
	.flags = BPF_F_SLEEPABLE,
	.runs = -1,
},
